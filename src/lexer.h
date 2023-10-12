//
// Created by shecannotsee on 23-10-10.
//

#ifndef SHE_INI_PARSE_LEXER_H
#define SHE_INI_PARSE_LEXER_H

#include <ini_type.h>
#include <string>
#include <vector>
#include <tuple>

namespace ini_parse {

struct token {
  lexer_type type;
  std::string value;
};

template<typename char_type>
class lexer {
 public:
  // copy:off
  lexer(const lexer&) = delete;
  lexer& operator=(const lexer&) = delete;
  // move:off
  lexer(lexer&&) = delete;
  lexer& operator=(lexer&&) = delete;
  // destructors
  ~lexer() = default;
  // constructors
  lexer() = default;

 private:
  // deal '\'
  std::tuple<int,int> one_line_divide(const std::vector<char_type>& buffer,int start_index) {
    bool escape_symbol= false;
    for (int i = start_index; i<buffer.size(); ++i) {
      /*zzz*/if (buffer[i] == '\n' && escape_symbol == false) {
        return std::make_tuple(start_index, i);
      } else if (buffer[i] == '\n' && escape_symbol == true) {
        escape_symbol = false;
      } else if (buffer[i] == '\\') {
        escape_symbol = true;
      } else if (buffer[i] == ' ') {
        continue;
      } else {
        escape_symbol = false;
      }
    }
  };

  // clear ' ', '\' , '\n'
  void process_one_line(const std::vector<char_type>& buffer, int start, int end, std::vector<lexer_type>& tokens) {
    auto temp = std::move(std::vector<char_type>(buffer.begin()+start,buffer.begin()+end));
  };

 public:
  std::vector<lexer_type> get_token(const std::vector<char_type>& buffer) {
    std::vector<lexer_type> ret;
    int start = 0;
    while (start<buffer.size()) {
      auto index = this->one_line_divide(buffer, start);
      // ignore single line with '\n'
      this->process_one_line(buffer, std::get<0>(index), std::get<1>(index), ret);

      start = std::get<1>(index) + 1;
    }
    return ret;
  };

};


} // ini_parse

#endif //SHE_INI_PARSE_LEXER_H
