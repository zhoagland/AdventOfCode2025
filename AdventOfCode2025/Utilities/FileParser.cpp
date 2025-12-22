#include "FileParser.h"

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
