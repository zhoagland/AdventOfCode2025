#ifndef _AOC_H_
#define _AOC_H_

#include <filesystem>

class AOC {
public:
	virtual ~AOC() {};
	virtual int CalculateAnswer() = 0;
	virtual int CalculatePt2Answer() = 0;
	virtual int Parser() = 0;

protected:
	int test_answer_;
	int answer_;
	std::filesystem::path file_path_;
};

#endif // !_AOC_H_
