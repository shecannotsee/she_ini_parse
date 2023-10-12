//
// Created by shecannotsee on 23-10-13.
//

#include "ini_parse.h"
#include "scan.h"
#include "lexer.h"
#include "parse.h"

namespace she {

ini_parse::ini_parse(const std::string& file_path) {
  // scan
  she::scan scanning(file_path);
  auto buffer = scanning.get();/* deal last char */ {
    if (buffer[buffer.size() - 1] != '\n') {
      buffer.emplace_back('\n');
    }
  }
  // lexer
  she::lexer<char> lexer_test;
  auto tokens = lexer_test.get_token(buffer);
  // parse
  she::parse parse;
  AST_ = parse.parsing(tokens);
  AST_.root = file_path;
}

std::vector<std::string> ini_parse::get_all_section() const {
  return this->AST_.section.value;
}

std::vector<std::string> ini_parse::get_all_key(const std::string& section) {
  if (this->AST_.section.index.find(section)!=AST_.section.index.end()) {
    auto index = this->AST_.section.index[section] - 1;
    std::vector<std::string> keys;
    for (const auto& key : this->AST_.kvp[index].value) {
      keys.emplace_back(key.key);
    }
    return keys;
  } else {
    return {};
  }
}

std::vector<key_value_pair> ini_parse::get_kvp(const std::string& section) {
  if (this->AST_.section.index.find(section)!=AST_.section.index.end()) {
    int index = this->AST_.section.index[section];
    return this->AST_.kvp[index-1].value;
  } else {
    return {};
  }
}

std::string ini_parse::get(std::string section, std::string key) {
  auto s_index = this->AST_.section.index[section];
  auto k_index = this->AST_.kvp[s_index-1].index[key];
  auto value = this->AST_.kvp[s_index-1].value[k_index-1].value;
  return value;
}

} // she