#ifndef _AOC_DAY_2_H_
#define _AOC_DAY_2_H_

#ifndef __cplusplus
#error
#endif // !__cplusplus

#include "../Utilities/AOC.h"
#include <string>

struct ID_Range {
	uint64_t start_;
	uint64_t end_;
	ID_Range(uint64_t start, uint64_t end) : start_(start), end_(end) {};
};

class AOC_Day2 final {
public:
	explicit AOC_Day2();
	~AOC_Day2() noexcept;

	uint64_t CalculateAnswer();
	uint64_t CalculatePt2Answer();
private:
	uint64_t answer_;
};

#endif // !_AOC_DAY_2_H_
