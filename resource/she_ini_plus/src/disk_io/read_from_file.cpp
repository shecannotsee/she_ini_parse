//
// Created by shecannotsee on 23-7-27.
//

#include "read_from_file.h"
#include <stdexcept>

she_ini_plus::read_from_file::read_from_file(const std::string& path) noexcept {
  file_handle_ = fopen(path.c_str(),"r");
  if (file_handle_ == NULL) {
    throw std::runtime_error("Failed to open file."); // 抛出运行时错误异常
  }
}

she_ini_plus::read_from_file::~read_from_file() {
  fclose(file_handle_);
}

std::tuple<bool, char> she_ini_plus::read_from_file::get() {
  char c;
  while ((c = fgetc(file_handle_)) != EOF) {
    return std::make_pair(true,c);
  }
  return std::make_pair(false,'\0');
}
