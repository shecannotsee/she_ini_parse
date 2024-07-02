//
// Created by shecannotsee on 23-8-4.
//

#ifndef SHE_INI_PLUS_TEST_LEXER_T_MATCHING_H_
#define SHE_INI_PLUS_TEST_LEXER_T_MATCHING_H_

#include <lexer/matching.h>
#include <string>
#include <vector>
#include <algorithm>

TEST(a,b) {
  using matching = she_ini_plus::matching;
  using TOKEN_TYPE = she_ini_plus::TOKEN_TYPE;
  using SYMBOL_TYPE = she_ini_plus::SYMBOL_TYPE;
  using token = matching::token;
  matching matching_tool;

  std::vector<char> character_stream;
  auto string_to_vector = [&character_stream](std::string str){
    std::copy(str.begin(), str.end(), std::back_inserter(character_stream));
  };
  token return_token{SYMBOL_TYPE ::UNKNOWN,""};

  // boundary test


  // logical test
  string_to_vector("#\n");
  return_token = matching_tool.token_generation(character_stream);
  EXPECT_EQ(matching::get_token_type(return_token),SYMBOL_TYPE::COMMENTS);
  EXPECT_EQ(matching::get_token_str(return_token),"123");



}

#endif //SHE_INI_PLUS_TEST_LEXER_T_MATCHING_H_
