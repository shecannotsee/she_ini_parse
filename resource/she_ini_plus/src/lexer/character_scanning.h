//
// Created by shecannotsee on 23-7-27.
//

#ifndef SHE_INI_PLUS_SRC_LEXER_CHARACTER_SCANNING_H_
#define SHE_INI_PLUS_SRC_LEXER_CHARACTER_SCANNING_H_

#include <disk_io/read_from_file.h>
#include <vector>

namespace she_ini_plus {

class character_scanning {
 public:
  character_scanning() = delete;
  /**
   * @brief constructor
   * @param file_path Set the path for reading files
   * @param size Set the size of the read buffer
   */
  explicit character_scanning(const std::string& file_path,const int& size = 1) noexcept;
  ~character_scanning() = default;

 private:
  int buffer_size_{1};
  using file_handle = read_from_file;
  file_handle file_;

 public:
  /**
   * @brief set the size of the read buffer.
   * @param size buffer size
   */
  void set_buffer_size(int size) {
    buffer_size_ = size;
  }

  /**
   * @brief Get strings.
   * @return string buffer
   */
  std::vector<char> getchar();
};

} // she_ini_plus

#endif //SHE_INI_PLUS_SRC_LEXER_CHARACTER_SCANNING_H_
