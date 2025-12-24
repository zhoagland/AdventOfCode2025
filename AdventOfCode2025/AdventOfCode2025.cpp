#include <print>
#include "AOC_Day1/AOC_Day1.h"
#include "AOC_Day2/AOC_Day2.h"

int main()
{
	AOC_Day1 Day1Answer;
	std::println("Answer To day 1 is: {}", Day1Answer.CalculateAnswer());
	std::println("Answer To day 1 pt2 is: {}", Day1Answer.CalculatePt2Answer());

	AOC_Day2 Day2Answer;
	std::println("Answer To day 2 is: {}", Day2Answer.CalculateAnswer());
	std::println("Answer To day 2 pt2 is: {}", Day2Answer.CalculatePt2Answer());

	return 0;
}
