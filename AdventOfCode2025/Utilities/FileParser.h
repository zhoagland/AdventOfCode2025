#ifndef _AOC_UTILITIES_H_
#define _AOC_UTILITIES_H_

#include <filesystem>
#include <vector>

template<typename T>
class FileParser {
public:
	FileParser(std::filesystem::path);
	~FileParser();

	constexpr std::vector<T>& get_file_list() const;

private: 
	std::filesystem::path file_to_parse_;
	std::vector<T> file_list_;
};


#endif //_AOC_UTILITES_H_