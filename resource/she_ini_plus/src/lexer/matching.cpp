//
// Created by shecannotsee on 23-8-4.
//

#include "matching.h"

she_ini_plus::matching::token
she_ini_plus::matching::token_generation(std::vector<char> character_stream) {
  /*****/if (matching::get_token_type(token_buffer_[tbp_]) == SYMBOL_TYPE::UNKNOWN) {

  } else if (matching::get_token_type(token_buffer_[tbp_]) == SYMBOL_TYPE::WAITING) {
    // do nothing.
  }

  get_token_status get_token_success{false};
  for(auto ch:character_stream) {
    if (get_token_success) {

    } else {

    }
    get_token_success = this->single_character_processing(ch);
  }

  return token_buffer_[tbp_];
}

she_ini_plus::matching::get_token_status
she_ini_plus::matching::single_character_processing(char ch) {

  /***/if (symbol_table[ch] == SYMBOL_TYPE::MAY_COMMENTS) {
    // '/' && '/' -> "//"
    if (matching::get_token_type(token_buffer_[tbp_]) == SYMBOL_TYPE::MAY_COMMENTS) {
      this->set_token_type(SYMBOL_TYPE::COMMENTS);
      matching::get_token_str(token_buffer_[tbp_]).push_back(ch);
      return true;
    }
    this->set_token_type(SYMBOL_TYPE::MAY_COMMENTS);
    std::get<1>(token_buffer_[tbp_]).push_back(ch);
    return false;
  }
  else if () {

  }
  else {
    std::get<1>(token_buffer_[tbp_]).push_back(ch);
    return false;
  }
}
