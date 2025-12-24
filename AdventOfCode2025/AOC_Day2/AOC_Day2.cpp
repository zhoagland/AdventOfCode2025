#include "AOC_Day2.h"
#include "../Utilities/FileParser.h"
#include <string>
#include <vector>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <unordered_map>
#include <print>


AOC_Day2::AOC_Day2() {
	answer_ = 0;
}

AOC_Day2::~AOC_Day2() {

}

// Helper: trim whitespace from both ends
static inline std::string trim(const std::string& s) {
	auto begin = s.begin();
	while (begin != s.end() && std::isspace(static_cast<unsigned char>(*begin))) ++begin;
	auto end = s.end();
	do { --end; } while (std::distance(begin, end) >= 0 && std::isspace(static_cast<unsigned char>(*end)));
	return std::string(begin, end + 1);
}

// Helper: parse a single "start-end" string into ID_Range
static ID_Range ParseRange(const std::string& token) {
	std::string t = trim(token);
	auto sep = t.find('-');
	if (sep == std::string::npos) {
		// malformed input: return a zero range (adjust as needed)
		return ID_Range(0, 0);
	}
	std::string left = trim(t.substr(0, sep));
	std::string right = trim(t.substr(sep + 1));
	uint64_t start = 0;
	uint64_t end = 0;
	try {
		start = std::stoull(left);
		end = std::stoull(right);
	} catch (...) {
		// on conversion error return zero range (adjust error handling as needed)
		return ID_Range(0, 0);
	}
	return ID_Range(start, end);
}



uint64_t AOC_Day2::CalculateAnswer() { 

	//ID with repeating digits are bad
	// No number has a leading zero.
	// We are given a range to iterate through
	// If the number contains repeating digits it is invalid.
	// So the number has to have an even number of chars.
	// and the first half has to match the second half.
	// So get a number in the range. Convert to string.
	// If string.size() % 2 != 0 skip
	// else if string.substring(0, string.size()/2) == string.substring(string.size()/2 + 1, string.size())
	//		convert string to int and add to total.
	uint64_t id_total = 0;

	std::ifstream file;
	file.open("C:/Users/zahoa/source/repos/AdventOfCode2025/AdventOfCode2025/AOC_Day2/AOC_Day2_Puzzle.txt");

	if (!file.is_open()) {
		return -1;
	}
	else {
		std::string line;
		while (std::getline(file, line, ',')) {
			ID_Range range = ParseRange(line);

			for (size_t id = range.start_; id <= range.end_; id++) {
				std::string id_string = std::to_string(id);

				if (id_string.size() % 2 == 0) {
					if (id_string.substr(0, id_string.size() / 2) == id_string.substr((id_string.size() / 2), id_string.size())) {
						id_total += static_cast<uint64_t>(id);
					}
				}

			}
		}
	}

	answer_ = id_total;
	return answer_;
}

uint64_t AOC_Day2::CalculatePt2Answer() {
	
	//For part 2 it is invalid if a sequence is repeated at least twice.
	// so as we see a new number push it into a map.
	// if we see a number that repeats check to see if the previous set of numbers match
	// the next set of those number of numbers

	uint64_t id_total = 0;

	std::ifstream file;
	file.open("C:/Users/zahoa/source/repos/AdventOfCode2025/AdventOfCode2025/AOC_Day2/AOC_Day2_Test.txt");

	if (!file.is_open()) {
		return -1;
	}
	else {
		std::string line;
		while (std::getline(file, line, ',')) {
			ID_Range range =ParseRange(line);

			for (size_t id = range.start_; id <= range.end_; id++) {
				std::unordered_map<char, bool> seen_chars;
				std::string id_string = std::to_string(id);

				for (size_t current_idx = 0; current_idx < id_string.size(); current_idx++) {
					// if number is already in map
					if (seen_chars.count(id_string[current_idx])) {
						// make sure the previous number of chars could be a pattern of the correct size.
						if (id_string.size() % current_idx == 0)
						{
							bool match_result = true;
							std::string substring = id_string.substr(0, seen_chars.size());
							for (size_t match_counter = 1; match_counter < id_string.size() / current_idx; match_counter++) {
								std::string prev_substring;
								prev_substring = substring;

								substring = id_string.substr(current_idx * match_counter, seen_chars.size());

								if (prev_substring == substring) {
									match_result &= true;
								}
								else {
									match_result &= false;
								}


							}
							if (match_result) {

								std::println("{}", id_string);

								id_total += static_cast<uint64_t>(id);
								continue;
							}

						}
						else {
							break;
						}
					}
					else {
						seen_chars.insert({ id_string[current_idx], true });
					}

				}
			}
		}
	}

	answer_ = id_total;
	return answer_;
}
