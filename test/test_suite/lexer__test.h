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

ini_parse::lexer_type get_lexer_type(std::tuple<ini_parse::lexer_type,std::string> tokens) {
  return std::get<0>(tokens);
}
std::string get_value(std::tuple<ini_parse::lexer_type,std::string> tokens) {
  std::get<1>(tokens);
}

TEST(lexer__test, token_validation) {
  ini_parse::scan scanning("../resource/lexer_test.ini");
  auto buffer = scanning.get();/* deal last char */ {
    if (buffer[buffer.size() - 1] != '\n') {
      buffer.emplace_back('\n');
    }
  }
  ini_parse::lexer<char> lexer_test;

  auto tokens = lexer_test.get_token(buffer);

  ASSERT_EQ(get_lexer_type(tokens[0]),ini_parse::lexer_type::SECTION_BEGIN);
  ASSERT_EQ(get_value(tokens[0]),std::string("["));
  ASSERT_EQ(get_lexer_type(tokens[1]),ini_parse::lexer_type::VALUE);
  ASSERT_EQ(get_value(tokens[1]),std::string("admin"));
  ASSERT_EQ(get_lexer_type(tokens[2]),ini_parse::lexer_type::SECTION_END);
  ASSERT_EQ(get_value(tokens[2]),std::string("]"));
  ASSERT_EQ(get_lexer_type(tokens[3]),ini_parse::lexer_type::LINE_BREAK);
  ASSERT_EQ(get_value(tokens[3]),std::string("\n"));

  ASSERT_EQ(get_lexer_type(tokens[4]),ini_parse::lexer_type::VALUE);
  ASSERT_EQ(get_value(tokens[4]),std::string("adress"));
  ASSERT_EQ(get_lexer_type(tokens[5]),ini_parse::lexer_type::TYPE_CONVERSION);
  ASSERT_EQ(get_value(tokens[5]),std::string("="));
  ASSERT_EQ(get_lexer_type(tokens[6]),ini_parse::lexer_type::VALUE);
  ASSERT_EQ(get_value(tokens[6]),std::string("aaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbb"));
  ASSERT_EQ(get_lexer_type(tokens[7]),ini_parse::lexer_type::LINE_BREAK);
  ASSERT_EQ(get_value(tokens[7]),std::string("\n"));

  ASSERT_EQ(get_lexer_type(tokens[4]),ini_parse::lexer_type::VALUE);
  ASSERT_EQ(get_value(tokens[4]),std::string("name"));
  ASSERT_EQ(get_lexer_type(tokens[5]),ini_parse::lexer_type::TYPE_CONVERSION);
  ASSERT_EQ(get_value(tokens[5]),std::string("="));
  ASSERT_EQ(get_lexer_type(tokens[6]),ini_parse::lexer_type::VALUE);
  ASSERT_EQ(get_value(tokens[6]),std::string("jack"));
  ASSERT_EQ(get_lexer_type(tokens[7]),ini_parse::lexer_type::LINE_BREAK);
  ASSERT_EQ(get_value(tokens[7]),std::string("\n"));

  ASSERT_EQ(get_lexer_type(tokens[4]),ini_parse::lexer_type::VALUE);
  ASSERT_EQ(get_value(tokens[4]),std::string("a"));
  ASSERT_EQ(get_lexer_type(tokens[7]),ini_parse::lexer_type::LINE_BREAK);
  ASSERT_EQ(get_value(tokens[7]),std::string("\n"));

  ASSERT_EQ(get_lexer_type(tokens[4]),ini_parse::lexer_type::VALUE);
  ASSERT_EQ(get_value(tokens[4]),std::string("des"));
  ASSERT_EQ(get_lexer_type(tokens[5]),ini_parse::lexer_type::TYPE_CONVERSION);
  ASSERT_EQ(get_value(tokens[5]),std::string("="));
  ASSERT_EQ(get_lexer_type(tokens[6]),ini_parse::lexer_type::VALUE);
  ASSERT_EQ(get_value(tokens[6]),std::string("asdsadasdasdasdasdasdasdasdsad"));
  ASSERT_EQ(get_lexer_type(tokens[7]),ini_parse::lexer_type::LINE_BREAK);
  ASSERT_EQ(get_value(tokens[7]),std::string("\n"));


  EXPECT_EQ(1,1);
}

#endif //SHE_INI_PARSE_LEXER__TEST_H
