//
// Created by shecannotsee on 23-10-10.
//

#ifndef SHE_INI_PARSE_TYPE_H
#define SHE_INI_PARSE_TYPE_H

#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>

namespace ini_parse {

enum class lexer_type {
  SECTION_BEGIN = '[',
  SECTION_END   = ']',
  TYPE_CONVERSION = '=',

  NOTE = '#',
  LINE_BREAK = '\n',

  ESCAPE = '\\',
  VALUE = 0
};

enum class parse_type {
  SECTION,
  KEY,
  VALUE,
  ERROR
};

struct section_mapping {
  std::vector<std::string> value;
  std::unordered_map<std::string, int> index;
  void add(const std::string& to_insert) {
    this->value.push_back(to_insert);
    index.insert(std::make_pair(to_insert,value.size()));
  }
};

struct key_value_pair {
  std::string key;
  std::string value;
};

struct kvp_mapping {
  std::vector<key_value_pair> value;
  std::unordered_map<std::string, int> index;
  void add(const key_value_pair& to_insert) {
    this->value.push_back(to_insert);
    index.insert(std::make_pair(to_insert.key,value.size()));
  }
};

struct AST{
  std::string root;
  section_mapping section;
  std::vector<kvp_mapping> kvp;
};

}

#endif //SHE_INI_PARSE_TYPE_H
