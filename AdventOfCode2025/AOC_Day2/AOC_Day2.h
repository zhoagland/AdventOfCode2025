#ifndef _AOC_DAY_2_H_
#define _AOC_DAY_2_H_

#include "../Utilities/AOC.h"

class AOC_Day2 final : AOC {
public:
	explicit AOC_Day2();
	~AOC_Day2() noexcept;

	int CalculateAnswer() override;
	int CalculatePt2Answer() override;

private:
	int Parser();
};

#endif // !_AOC_DAY_2_H_
