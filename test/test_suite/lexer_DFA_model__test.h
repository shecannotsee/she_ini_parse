//
// Created by shecannotsee on 23-10-12.
//

#ifndef SHE_INI_PARSE_LEXER_DFA_MODEL__TEST_H
#define SHE_INI_PARSE_LEXER_DFA_MODEL__TEST_H

#include <lexer_DFA_model.h>

TEST(lexer_DFA_model__test,running) {
  ini_parse::lexer_DFA_model::transition_status<char>('a');
}

#endif //SHE_INI_PARSE_LEXER_DFA_MODEL__TEST_H
