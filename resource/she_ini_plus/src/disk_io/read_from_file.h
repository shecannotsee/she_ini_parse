//
// Created by shecannotsee on 23-7-27.
//

#ifndef SHE_INI_PLUS_SRC_DISK_IO_READ_FROM_FILE_H_
#define SHE_INI_PLUS_SRC_DISK_IO_READ_FROM_FILE_H_

#include <string>
#include <tuple>

namespace she_ini_plus {

/**
 * @brief
 * @example
 */
class read_from_file {
 public:
  read_from_file() = delete;
  read_from_file(const std::string& path) noexcept;
  ~read_from_file();

 private:
  FILE* file_handle_; ///< file handle.

 public:
  /**
   * @brief This function is used to retrieve a single character in a file.
   * @return bool:is there a valid character.char:valid character
   */
  std::tuple<bool,char> get();

  /**
   * @brief Obtain bool type in tuple.
   * @param ret read_from_file::get()
   * @return Returns type bool in tuple
   */
  static bool data_is_valid(std::tuple<bool,char> ret) {
    return std::get<0>(ret);
  };

  /**
   * @brief Obtain char type in tuple.
   * @param ret read_from_file::get()
   * @return Returns type char in tuple
   */
  static char valid_data(std::tuple<bool,char> ret) {
    return std::get<1>(ret);
  }

};

} // she_ini_plus

#endif //SHE_INI_PLUS_SRC_DISK_IO_READ_FROM_FILE_H_
