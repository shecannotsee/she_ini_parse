//
// Created by shecannotsee on 23-10-10.
//

#ifndef SHE_INI_PARSE_LEXER_H
#define SHE_INI_PARSE_LEXER_H

#include <ini_type.h>
#include <lexer_DFA_model.h>
#include <string>
#include <vector>
#include <tuple>

namespace she {


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
  // equal to lexer_DFA_model
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
  void process_one_line(const std::vector<char_type>& buffer, int start, int end, std::vector<std::tuple<lexer_type,std::string>>& tokens) {
    std::vector<char_type> generate_token_buffer{};
    auto state = lexer_DFA_model::start_state;
    for (int i = start; i < end; ++i) {
      state = lexer_DFA_model::transition_status(state,buffer[i]);
      if (state==lexer_DFA_model::states::S1 && buffer[i]!=' '&&buffer[i]!='\n') {
        generate_token_buffer.emplace_back(buffer[i]);
      }
    }
    this->set_token(generate_token_buffer,tokens);
    // Prevent redundant line breaks
    if (!tokens.empty() && std::get<0>(tokens.back())!=lexer_type::LINE_BREAK) {
      tokens.emplace_back(lexer_type::LINE_BREAK, std::string("\n"));
    }
  };

  // no ' ', '\', '\n'
  void set_token(std::vector<char_type>& buffer, std::vector<std::tuple<lexer_type,std::string>>& tokens) {
    auto commit_token = [&](int max, lexer_type _){
      std::string value;
      for (int i = 0; i < max; ++i) {
        value += buffer[i];
      }
      if (!value.empty())
        tokens.emplace_back(_,value);
    };
    int index = 0;
    for (int i = 0; i < buffer.size(); ++i) {
      /**zz*/if (buffer[i] == '[') {
        commit_token(index,lexer_type::VALUE);
        buffer[0] = buffer[i];
        index = 1;
        commit_token(index,lexer_type::SECTION_BEGIN);
        index = 0;
      } else if (buffer[i] == ']') {
        commit_token(index,lexer_type::VALUE);
        buffer[0] = buffer[i];
        index = 1;
        commit_token(index,lexer_type::SECTION_END);
        index = 0;
      } else if (buffer[i] == '=') {
        commit_token(index,lexer_type::VALUE);
        buffer[0] = buffer[i];
        index = 1;
        commit_token(index,lexer_type::TYPE_CONVERSION);
        index = 0;
      } else if (buffer[i] == '#') {
        break;
      } else {
        buffer[index] = buffer[i];
        index++;
      }

    }

    commit_token(index,lexer_type::VALUE);
  }


 public:
  std::vector<std::tuple<lexer_type,std::string>> get_token(const std::vector<char_type>& buffer) {
    std::vector<std::tuple<lexer_type,std::string>> ret;
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
