#ifndef _AOC_UTILITIES_H_
#define _AOC_UTILITIES_H_

#ifndef __cplusplus
#error
#endif // !__cplusplus

#include <filesystem>
#include <vector>
#include <concepts>
#include <string>
#include <type_traits>


template<typename T>
class FileParser {
public:
	explicit FileParser(std::filesystem::path path);
	~FileParser() noexcept;

	template<typename F>
	requires std::invocable<F, std::string>&& 
	    std::convertible_to<std::invoke_result_t<F, std::string>, T>
	void parse(F&& line_parser);

	constexpr std::vector<T>& get_file_list() const;

private: 
	std::filesystem::path file_to_parse_;
	std::vector<T> file_list_;
};


#endif //_AOC_UTILITES_H_