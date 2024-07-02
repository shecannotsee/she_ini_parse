//
// Created by shecannotsee on 23-8-4.
//

#ifndef SHE_INI_PLUS_SRC_LEXER_MATCHING_H_
#define SHE_INI_PLUS_SRC_LEXER_MATCHING_H_

#include <tuple>
#include <string>
#include <utility>
#include <vector>
#include <symbol_table.h>

namespace she_ini_plus {

class matching {
 public:
  matching() = default;
  ~matching() = default;

 public:
  using token = std::tuple<SYMBOL_TYPE,std::string>;

 private:
  static constexpr int DOUBLE_BUFFER_SIZE = 2;
  token token_buffer_[DOUBLE_BUFFER_SIZE] = {
      {SYMBOL_TYPE::UNKNOWN,""},
      {SYMBOL_TYPE::UNKNOWN,""}
  }; ///< temp to save token
  int tbp_{0}; ///< double buffer pointer

  void set_token_type(SYMBOL_TYPE symbol_type) {
    std::get<0>(token_buffer_[tbp_]) = symbol_type;
  }
  void set_token_value(std::string str) {
    std::get<1>(token_buffer_[tbp_]) = std::move(str);
  }

 private:
  using get_token_status = bool;
  /**
   * @brief
   * @param ch
   * @return
   */
  get_token_status single_character_processing(char ch);

 public:
  /**
   * @brief Convert char stream to token output
   * @param character_stream char stream
   * @return token,including the type and string of the token
   */
  token token_generation(std::vector<char> character_stream);

  /**
   * @brief Get token type.
   * @param return_token token_generation() return
   * @return token type
   */
  static SYMBOL_TYPE get_token_type(token return_token) {
    std::get<0>(return_token);
  }

  /**
   * @brief Get token string
   * @param return_token token_generation() return
   * @return token string,type is std::string
   */
  static std::string get_token_str(token return_token) {
    std::get<1>(return_token);
  }

};

} // she_ini_plus

#endif //SHE_INI_PLUS_SRC_LEXER_MATCHING_H_
