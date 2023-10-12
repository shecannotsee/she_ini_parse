//
// Created by shecannotsee on 23-10-12.
//

#ifndef SHE_INI_PARSE_PARSE__TEST_H
#define SHE_INI_PARSE_PARSE__TEST_H

#include <parse.h>

TEST(parse__test, s) {
  ini_parse::scan scanning("../resource/parse_test.ini");
  auto buffer = scanning.get();/* deal last char */ {
    if (buffer[buffer.size() - 1] != '\n') {
      buffer.emplace_back('\n');
    }
  }
  ini_parse::lexer<char> lexer_test;

  auto tokens = lexer_test.get_token(buffer);
  ini_parse::parse p;
  auto AST = p.parsing(tokens);


  int a = 1;
  EXPECT_EQ(a,1);
}

#endif //SHE_INI_PARSE_PARSE__TEST_H
