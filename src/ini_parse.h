//
// Created by shecannotsee on 23-10-13.
//

#ifndef SHE_INI_PARSE_INI_PARSE_H
#define SHE_INI_PARSE_INI_PARSE_H

#include <string>
#include <ini_type.h>

namespace she {

class ini_parse {
 public:
  // copy:off
  ini_parse(const ini_parse&) = delete;
  ini_parse& operator=(const ini_parse&) = delete;
  // move:off
  ini_parse(ini_parse&&) = delete;
  ini_parse& operator=(ini_parse&&) = delete;
  // destructors
  ~ini_parse() = default;
  // constructors
  explicit ini_parse(const std::string& file_path);

 private:
  AST AST_;

 public:
  std::vector<std::string> get_all_section() const;

  std::vector<std::string> get_all_key(const std::string& section);

  std::vector<key_value_pair> get_kvp(const std::string& section);

  std::string get(std::string section,std::string key);


};


} // she

#endif //SHE_INI_PARSE_INI_PARSE_H
