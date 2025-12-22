#include "FileParser.h"
#include <fstream>
#include <concepts>
#include <type_traits>
#include <string>
#include <vector>

template<typename T>
FileParser<T>::FileParser(std::filesystem::path file) : file_to_parse_(file){

}

template<typename T>
FileParser<T>::~FileParser() {

}

template<typename T>
constexpr std::vector<T>& FileParser<T>::get_file_list() const {
	return file_list_;
}

template<typename T>
template<typename F>
requires std::invocable<F, std::string>&&
std::convertible_to<std::invoke_result_t<F, std::string>, T>
inline void FileParser<T>::parse(F&& line_parser) {
    std::ifstream file(file_to_parse_);
    std::string line;
    while (std::getline(file, line)) {
        // No function pointer overhead; compiler inlines this call
        file_list_.push_back(line_parser(line));
    }
}