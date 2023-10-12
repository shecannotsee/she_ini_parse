//
// Created by shecannotsee on 23-10-12.
//

#ifndef SHE_INI_PARSE_PARSE__TEST_H
#define SHE_INI_PARSE_PARSE__TEST_H

#include <parse.h>

TEST(parse__test, ast) {
  she::scan scanning("../resource/parse_test.ini");
  auto buffer = scanning.get();/* deal last char */ {
    if (buffer[buffer.size() - 1] != '\n') {
      buffer.emplace_back('\n');
    }
  }
  she::lexer<char> lexer_test;

  auto tokens = lexer_test.get_token(buffer);
  she::parse p;
  auto AST = p.parsing(tokens);

  AST.root = "../resource/parse_test.ini";

  int section_times = 0;
  // check section
  for (int i = 0; i < AST.section.value.size(); ++i) {
    ASSERT_EQ(AST.section.value[i],std::string("s"+std::to_string(i+1)));
    section_times++;
  }
  ASSERT_EQ(section_times, 10);

  int kvp_times = 0;
  // check kvp
  for (int i =0; i < AST.section.value.size(); ++i) {
    std::string s_name = "s" + std::to_string(i+1);
    auto s_size = AST.section.index[s_name];
    auto kvp_size = s_size;
    auto kvp_index = kvp_size - 1;
    for (int j = 0; j < kvp_size; ++j) {
      auto kvp = AST.kvp[kvp_index];
      std::string k_name = "k" + std::to_string(j+1);
      std::string v_name = "v" + std::to_string(j+1);
      ASSERT_EQ(kvp.value[j].key,   k_name);
      kvp_times++;
      ASSERT_EQ(kvp.value[j].value, v_name);
      kvp_times++;
    }
  }
  constexpr int teal_times = 2*(1+2+3+4+5+6+7+8+9+10);
  ASSERT_EQ(kvp_times, teal_times);
}

#endif //SHE_INI_PARSE_PARSE__TEST_H
