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

TEST(lexer__test, one_line_divide) {
  ini_parse::scan scanning("../resource/lexer_test.ini");
  auto buffer = scanning.get();/* deal last char */ {
    if (buffer[buffer.size() - 1] != '\n') {
      buffer.emplace_back('\n');
    }
  }
  ini_parse::lexer<char> lexer_test;

  int start = 0;
  /* line1 */ {
    std::string line = "[admin]\n";
    auto index = lexer_test.one_line_divide(buffer, start);
    int end = std::get<1>(index);
    if (start == end) end = start+1;
    bool check_running = false;
    for (int i = start,j=0; i < end; ++i) {
      ASSERT_EQ(buffer[i],line[j]);
      j++;
      check_running = true;
    }
    ASSERT_EQ(check_running,true);
    start = std::get<1>(index) + 1;
  }
  /* line2 */ {
    std::string line = "adress = aaaaaaaaaaaaaaaaaaaaaaaaaaaa\\\n         bbbbbbbbbbbb\n";
    auto index = lexer_test.one_line_divide(buffer, start);
    int end = std::get<1>(index);
    if (start == end) end = start+1;
    bool check_running = false;
    for (int i = start,j=0; i < end; ++i) {
      ASSERT_EQ(buffer[i],line[j]);
      j++;
      check_running = true;
    }
    ASSERT_EQ(check_running,true);
    start = std::get<1>(index) + 1;
  }
  /* line3 */ {
    std::string line = "name = jac\\\n          k\n";
    auto index = lexer_test.one_line_divide(buffer, start);
    int end = std::get<1>(index);
    if (start == end) end = start+1;
    bool check_running = false;
    for (int i = start,j=0; i < end; ++i) {
      ASSERT_EQ(buffer[i],line[j]);
      j++;
      check_running = true;
    }
    ASSERT_EQ(check_running,true);
    start = std::get<1>(index) + 1;
  }
  /* line4 */ {
    std::string line = "\n";
    auto index = lexer_test.one_line_divide(buffer, start);
    int end = std::get<1>(index);
    if (start == end) end = start+1;
    bool check_running = false;
    for (int i = start,j=0; i < end; ++i) {
      ASSERT_EQ(buffer[i],line[j]);
      j++;
      check_running = true;
    }
    ASSERT_EQ(check_running,true);
    start = std::get<1>(index) + 1;
  }
  /* line5 */ {
    std::string line = "a\n";
    auto index = lexer_test.one_line_divide(buffer, start);
    int end = std::get<1>(index);
    if (start == end) end = start+1;
    bool check_running = false;
    for (int i = start,j=0; i < end; ++i) {
      ASSERT_EQ(buffer[i],line[j]);
      j++;
      check_running = true;
    }
    ASSERT_EQ(check_running,true);
    start = std::get<1>(index) + 1;
  }
  /* line6 */ {
    std::string line = "des = asdsadasd\\asdasdasdas\\dasdasdsad\n";
    auto index = lexer_test.one_line_divide(buffer, start);
    int end = std::get<1>(index);
    if (start == end) end = start+1;
    bool check_running = false;
    for (int i = start,j=0; i < end; ++i) {
      ASSERT_EQ(buffer[i],line[j]);
      j++;
      check_running = true;
    }
    ASSERT_EQ(check_running,true);
    start = std::get<1>(index) + 1;
  }

}

TEST(lexer__test, process_one_line) {
  ini_parse::scan scanning("../resource/lexer_test.ini");
  auto buffer = scanning.get();/* deal last char */ {
    if (buffer[buffer.size() - 1] != '\n') {
      buffer.emplace_back('\n');
    }
  }
  ini_parse::lexer<char> lexer_test;

  auto token = lexer_test.get_token(buffer);

}

#endif //SHE_INI_PARSE_LEXER__TEST_H
