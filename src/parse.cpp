//
// Created by shecannotsee on 23-10-10.
//

#include "parse.h"

namespace ini_parse {

AST parse::parsing(const std::vector<std::tuple<lexer_type, std::string>>& tokens) {
  using token_type = std::vector<std::tuple<lexer_type, std::string>>;
  AST entity;
  for (int i = 0 , index = 0; i < tokens.size(); ++i) {
    lexer_type get_type = std::get<0>(tokens[i]);
    if ( get_type == lexer_type::LINE_BREAK ) {
      int offset = i;
      if (offset > 0) {
        process_one_line(token_type(tokens.begin() + index, tokens.begin() + offset), entity);
        index = i+1;
      }
    }
  }
  return entity;
}

void parse::process_one_line(const std::vector<std::tuple<lexer_type, std::string>>& tokens, AST& entity) {
  parse_type type = this->syntax_analysis(tokens);
  if(type == parse_type::SECTION) {
    std::string section = std::get<1>(tokens[1]);
    /*****************************************************************************************************/
    entity.section.add(section);
    entity.kvp.push_back({});

  } else if (type == parse_type::KEY) {
    std::string key = std::get<1>(tokens[0]);
    std::string value = std::get<1>(tokens[2]);
    key_value_pair kvp;
    kvp.key   = key;
    kvp.value = value;
    /*****************************************************************************************************/
    auto s_name = entity.section.value.back();
    (entity.kvp.back()).add(kvp);


  } else {
    // TODO: Error handling
  }
}

parse_type parse::syntax_analysis(const std::vector<std::tuple<lexer_type, std::string>>& tokens) {
  unsigned char flag1 = 0x00;
  unsigned char flag2 = 0x00;
  unsigned char flag3 = 0x00;
  unsigned char check = 0x01;
  for (const auto& token : tokens) {
    auto l_type = std::get<0>(token);
    /*zzz*/if (l_type == lexer_type::SECTION_BEGIN) {
      flag1 = 0x01;
    } else if (l_type == lexer_type::TYPE_CONVERSION) {
      flag2 = 0x01;
    } else if (l_type == lexer_type::SECTION_END) {
      flag3 = 0x01;
    } else if (l_type == lexer_type::VALUE) {
      if (flag1) {// [s]
        flag2 = 0x00;
      } else {// k=v
        flag1 = 0x00;
        flag3 = 0x00;
      }
    }
  }
  if (flag1&&!flag2&&flag3) {
    return parse_type::SECTION;
  } else if (!flag1&&flag2&&!flag3) {
    return parse_type::KEY;
  } else {
    return parse_type::ERROR;
  }
}

} // ini_parse