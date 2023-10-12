//
// Created by shecannotsee on 23-10-10.
//

#ifndef SHE_INI_PARSE_PARSE_H
#define SHE_INI_PARSE_PARSE_H

#include <ini_type.h>
#include <string>
#include <tuple>
#include <vector>

namespace ini_parse {

class parse {
 public:
  // copy:off
  parse(const parse&) = delete;
  parse& operator=(const parse&) = delete;
  // move:off
  parse(parse&&) = delete;
  parse& operator=(parse&&) = delete;
  // destructors
  ~parse() = default;
  // constructors
  parse() = default;

 private:
  // process one section
  void process_one_line(const std::vector<std::tuple<lexer_type,std::string>>& one_section, AST& entity);

  parse_type syntax_analysis(const std::vector<std::tuple<lexer_type, std::string>>& tokens);

 public:
  // interface
  AST parsing(const std::vector<std::tuple<lexer_type, std::string>>& tokens);

};


} // ini_parse

#endif //SHE_INI_PARSE_PARSE_H
