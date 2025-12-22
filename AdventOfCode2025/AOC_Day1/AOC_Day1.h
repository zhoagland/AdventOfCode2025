#ifndef _AOC_DAY_1_H_
#define _AOC_DAY_1_H_

#include <memory>
#include <array>

class AOC_Day1 {
public:
	AOC_Day1();
	~AOC_Day1();


	//Copy not needed
	AOC_Day1(const AOC_Day1&) = delete;
	AOC_Day1& operator=(const AOC_Day1&) = delete;
	
	//Move not needed
	AOC_Day1(AOC_Day1&& other) = delete;
	AOC_Day1& operator=(AOC_Day1&& other) = delete;

	int CalculateAnswer();
	int CalculateAnswerPt2();

private:
	bool TestCode();
	int answer_;
	int answerpt2_;
};


#endif // _AOC_DAY_1_H_
