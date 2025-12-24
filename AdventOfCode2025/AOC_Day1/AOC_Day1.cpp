#include <filesystem>
#include <vector>
#include <fstream>
#include <memory>
#include "AOC_Day1.h"

const int kLockPositions = 100;

struct Instruction {
	char direction_;
	int step_;
	Instruction(char direction = 'L', int step = 0) : direction_(direction), step_(step) {};
};

static Instruction ParseToken(std::string_view token) {
	Instruction ins{};
	if (token.empty()) return ins;

	ins.direction_ = static_cast<char>(std::toupper(static_cast<unsigned char>(token[0])));

	std::string_view numview = token.substr(1);
	if (numview.empty()) return ins;

	int value = 0;
	auto res = std::from_chars(numview.data(), numview.data() + numview.size(), value);
	if (res.ec == std::errc()) {
		ins.step_ = value;
	}
	else {
		// handle parse error (leave step_ as 0 or set an error flag)
	}
	return ins;
}

class FileParser {
public:
	FileParser(std::filesystem::path path) : path_(path) {}
	
	int Parse() {
		std::ifstream file;
		file.open(path_.string());

		if (!file.is_open()) {
			return -1;
		} else {
			std::string line;
			while (std::getline(file, line)) {
					instructions_.push_back(std::move(ParseToken(std::string_view(line))));
			}

		}
		return 0;
	}

	std::vector<Instruction>& get_instructions() { return instructions_; };

private:

	std::filesystem::path path_;
	std::vector<Instruction> instructions_;
};


AOC_Day1::AOC_Day1() {
	answerpt2_ = 0;
	answer_ = 0;
}

AOC_Day1::~AOC_Day1() {}


static int puzzle_logic(FileParser file) {
	int lock_number = 50;
	int code = 0;

	for (Instruction next_instruction : file.get_instructions()) {

		if(next_instruction.step_ >= 100) {
			next_instruction.step_ = next_instruction.step_ % 100;
		}

		if (next_instruction.direction_ == 'L') {
			// Subtract.
			if (lock_number - next_instruction.step_ < 0) {
				lock_number = lock_number - next_instruction.step_ + kLockPositions;
			}
			else {
				lock_number -= next_instruction.step_;
			}
		}
		else {
			// Add
			if (lock_number + next_instruction.step_ > 99) {
				lock_number = lock_number + next_instruction.step_ - kLockPositions;
			}
			else {
				lock_number += next_instruction.step_;
			}
		}

		if (lock_number == 0) {
			code++;
		}
	}

	return code;
}


static int puzzle_logic2(FileParser file) {
	int lock_number = 50;
	int code = 0;

	for (Instruction next_instruction : file.get_instructions()) {
		int prv_lck_num = lock_number;

		if (next_instruction.step_ >= 100) {
			code += next_instruction.step_ / 100;
			next_instruction.step_ = next_instruction.step_ % 100;
		}

		if (next_instruction.direction_ == 'L') {
			// Subtract.
			lock_number -= next_instruction.step_;

			if (prv_lck_num == 0) {
				lock_number += kLockPositions;
			}

			if (lock_number <= 0) {
				lock_number += kLockPositions;
				code++;
			}

		}

		if (next_instruction.direction_ == 'R') {
			// Add
			lock_number += next_instruction.step_;

			if (prv_lck_num == kLockPositions) {
				lock_number -= kLockPositions;
			}

			if (lock_number >= kLockPositions) {
				lock_number -= kLockPositions;
				code++;
			}
		}
	}

 	return code;
}

bool AOC_Day1::TestCode() {
	const int kTestAnswer = 3;
	const int kTestAnswer2 = 6;

	FileParser test_file(std::filesystem::path("C:/Users/zahoa/source/repos/AdventOfCode2025/AdventOfCode2025/AOC_Day1/AOC_Day1_Test.txt"));
	test_file.Parse();

	if (puzzle_logic(test_file) != kTestAnswer)
		return false;
	if (puzzle_logic2(test_file) != kTestAnswer2)
		return false;

	return true;
}

int AOC_Day1::CalculateAnswer(){
	
	if (!AOC_Day1::TestCode()) {
		return -1;
	}
	
	FileParser file(std::filesystem::path("C:/Users/zahoa/source/repos/AdventOfCode2025/AdventOfCode2025/AOC_Day1/AOC_Day1_Puzzle.txt"));
	file.Parse();

	answer_ = puzzle_logic(file);
	
	return answer_;
}

int AOC_Day1::CalculatePt2Answer() {

	if (!AOC_Day1::TestCode()) {
		return -1;
	}

	FileParser file(std::filesystem::path("C:/Users/zahoa/source/repos/AdventOfCode2025/AdventOfCode2025/AOC_Day1/AOC_Day1_Puzzle.txt"));
	file.Parse();

	answerpt2_ = puzzle_logic2(file);

	return answerpt2_;
}