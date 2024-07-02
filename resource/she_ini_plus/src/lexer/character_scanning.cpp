//
// Created by shecannotsee on 23-7-27.
//

#include "character_scanning.h"

she_ini_plus::character_scanning::character_scanning(const std::string &file_path, const int& size) noexcept
    : file_(file_path),
      buffer_size_(size) {
  // ...
}

std::vector<char> she_ini_plus::character_scanning::getchar() {
  std::vector<char> buffer(buffer_size_);

  std::tuple<bool,char> get_from_file;
  for (int i = 0; i < buffer_size_; ++i) {
    get_from_file = file_.get();
    if (file_handle::data_is_valid(get_from_file)) {
      buffer[i] = file_handle::valid_data(get_from_file);
    } else {
      buffer.resize(i);
      break;
    }
  }

  return buffer;
}
