//
// Created by shecannotsee on 23-10-10.
//

#include "scan.h"
#include <chrono>
#include <stdexcept>

namespace she {

scan::scan(const std::string &file_handle) {
  // create entity
  file_handle_ = std::make_unique<FILE>();
  // fopen to move
  file_handle_ = std::unique_ptr<FILE>(fopen(file_handle.c_str(),"r"));
  // Check if the file was successfully opened
  if (file_handle_ == nullptr) {
    throw std::runtime_error("Failed to open file path:"+file_handle);
  }
}

std::vector<char> scan::get() {
  std::vector<char> ret;
  char c = '\0';
  while ((c = fgetc(file_handle_.get())) != EOF ) {
    ret.emplace_back(c);
  }
  return ret;
}


} // ini_parse