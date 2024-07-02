//
// Created by shecannotsee on 23-7-27.
//

#ifndef SHE_INI_PLUS_SRC_LEXER_TOKEN_H_
#define SHE_INI_PLUS_SRC_LEXER_TOKEN_H_

#include <vector>
#include <symbol_table.h>

namespace she_ini_plus {

class token {
 private:
  using token_ = std::tuple<TOKEN_TYPE,std::string>;
 public:
  token() = default;
  ~token() = default;
 private:
  std::vector<token_> token_stream_;

 public:
  void add_token(token_ token);

};

} // she_ini_plus

#endif //SHE_INI_PLUS_SRC_LEXER_TOKEN_H_
