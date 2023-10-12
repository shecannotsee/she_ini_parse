//
// Created by shecannotsee on 23-10-10.
//

#ifndef SHE_INI_PARSE_SCAN_H
#define SHE_INI_PARSE_SCAN_H

#include <string>
#include <memory>
#include <queue>
#include <atomic>

namespace she {

class scan {
 public:
  // copy:off
  scan(const scan&) = delete;
  scan& operator=(const scan&) = delete;
  // move:on
  scan(scan&&)  noexcept = delete;
  scan& operator=(scan&&) = delete;
  // destructors
  ~scan() = default;
  // constructors
  explicit scan(const std::string& file_handle);

 private:
  std::unique_ptr<FILE> file_handle_; ///< file handle.

 public:
  std::vector<char> get();

};

} // ini_parse

#endif //SHE_INI_PARSE_SCAN_H
