//
// Created by shecannotsee on 23-10-12.
//

#ifndef SHE_INI_PARSE_LEXER_DFA_MODEL__TEST_H
#define SHE_INI_PARSE_LEXER_DFA_MODEL__TEST_H

#include <lexer_DFA_model.h>

TEST(lexer_DFA_model__test,running) {
  she::scan scanning("../resource/lexer_test.ini");
  auto buffer = scanning.get();/* deal last char */ {
    if (buffer[buffer.size() - 1] != '\n') {
      buffer.emplace_back('\n');
    }
  }
  using namespace she::lexer_DFA_model;

  std::vector<std::string> line = {
    {std::string("[admin]\n")},
    {std::string("adress = aaaaaaaaaaaaaaaaaaaaaaaaaaaa\\\n         bbbbbbbbbbbb\n")},
    {std::string("name = jac\\\n          k\n")},
    {std::string("\n")},
    {std::string("a\n")},
    {std::string("des = asdsadasd\\asdasdasdas\\dasdasdsad")}
  };
  std::vector<std::string> line_without_line_break = {
    {std::string("[admin]")},
    {std::string("adress = aaaaaaaaaaaaaaaaaaaaaaaaaaaa\\\n         bbbbbbbbbbbb")},
    {std::string("name = jac\\\n          k")},
    {std::string("")},
    {std::string("a")},
    {std::string("des = asdsadasd\\asdasdasdas\\dasdasdsad")}
  };

  // get data
  states state_now = start_state;
  std::vector<std::string> read_from;
  std::vector<std::string> read_from_without_line_break;
  int index = 0;
  for (int i=0; i<buffer.size(); ++i) {
    states get_state = transition_status(state_now,buffer[i]);
    if(get_state == accept_state) {
      read_from.emplace_back(buffer.begin()+index,buffer.begin()+i+1);// +1 means include buffer[i] this char
      read_from_without_line_break.emplace_back(buffer.begin()+index,buffer.begin()+i);
      index = i+1;
      state_now = start_state;
    } else if (get_state == she::lexer_DFA_model::states::REFUSE) {
      throw std::runtime_error("error to lexer");
    } else {
      state_now = get_state;
    }
  }

  /* test1 */ {
    int check_running = 0;
    for (int i = 0; i < line.size(); ++i) {
      for (int j = 0; j < line[i].size(); ++j) {
        ASSERT_EQ(line[i][j], read_from[i][j]);
      }
      check_running++;
    }
    ASSERT_EQ(check_running, 6); // check five times
  }

  /* test2 */ {
    int check_running = 0;
    for (int i = 0; i < line.size(); ++i) {
      for (int j = 0; j < line[i].size(); ++j) {
        ASSERT_EQ(line_without_line_break[i][j], read_from_without_line_break[i][j]);
      }
      check_running++;
    }
    ASSERT_EQ(check_running, 6); // check five times
  }
}

#endif //SHE_INI_PARSE_LEXER_DFA_MODEL__TEST_H
