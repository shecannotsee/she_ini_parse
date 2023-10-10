//
// Created by shecannotsee on 23-10-10.
//

#ifndef SHE_INI_PARSE_LEXER__TEST_H
#define SHE_INI_PARSE_LEXER__TEST_H
#define GTEST
#ifdef GTEST
#define private public
#define protected public
#endif

#include <lexer.h>

TEST(lexer__test, one_line) {
  ini_parse::scan scanning("../resource/lexer_test.ini");
  auto buffer = scanning.get();
  ini_parse::lexer<char> lexer_test;

  std::string line1 = "[admin]\n";
  {
    auto index = lexer_test.one_line(buffer,0);
    for (int i = std::get<0>(index),j=0; i < std::get<1>(index); ++i) {
      ASSERT_EQ(buffer[i],line1[j]);
      j++;
    }
  }
  std::string line2 = "adress = aaaaaaaaaaaaaaaaaaaaaaaaaaaa\\         bbbbbbbbbbbb";
  {
    auto index = lexer_test.one_line_divide(buffer,0);
    for (int i = std::get<0>(index),j=0; i < std::get<1>(index); ++i) {
      ASSERT_EQ(buffer[i],line1[j]);
      j++;
    }
  }
  std::string line3 = "name = jac\\          k";
  {
    auto index = lexer_test.one_line_divide(buffer,0);
    for (int i = std::get<0>(index),j=0; i < std::get<1>(index); ++i) {
      ASSERT_EQ(buffer[i],line1[j]);
      j++;
    }
  }
  std::string line4 = "des = asdsadasd\\asdasdasdas\\dasdasdsad";
  {
    auto index = lexer_test.one_line_divide(buffer,0);
    for (int i = std::get<0>(index),j=0; i < std::get<1>(index); ++i) {
      ASSERT_EQ(buffer[i],line1[j]);
      j++;
    }
  }

}

#endif //SHE_INI_PARSE_LEXER__TEST_H
