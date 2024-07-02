//
// Created by shecannotsee on 23-7-27.
//

#ifndef SHE_INI_PLUS_SRC_LEXER_SYMBOL_TABLE_H_
#define SHE_INI_PLUS_SRC_LEXER_SYMBOL_TABLE_H_

#include <string>
#include <unordered_map>

namespace she_ini_plus {

/**
 * @brief State during lexical analysis.
 */
enum class SYMBOL_TYPE : int {
  UNKNOWN,
  WAITING,      ///< Waiting for the next byte stream

  MAY_COMMENTS, ///< '/'
  COMMENTS,     ///< Comments,like "//" in c/c++.
  DELIMITER,    ///< Delimiter,like ';' in c/c++.
  OPERATOR,     ///< Operator,like '=','+' int c/c++
  TYPE_DEFINE,  ///< ":":Type definition symbol
  SECTION_BEGIN,///< "["
  SECTION_END,  ///< "]"
  REFERENCE,    ///< "&"
  ESCAPE_CHAR,  ///< "'\'"
  SPACE,        ///< " " and "\\t"
};

std::unordered_map<char, SYMBOL_TYPE> symbol_table {
    {'/',   SYMBOL_TYPE::MAY_COMMENTS},
    {'#',   SYMBOL_TYPE::COMMENTS},

    {';',   SYMBOL_TYPE::DELIMITER},
    {'\n',  SYMBOL_TYPE::DELIMITER},

    {'=',   SYMBOL_TYPE::OPERATOR},

    {':',   SYMBOL_TYPE::TYPE_DEFINE},

    {'[',   SYMBOL_TYPE::SECTION_BEGIN},
    {']',   SYMBOL_TYPE::SECTION_END},

    {'&',   SYMBOL_TYPE::REFERENCE},

    {'\\',  SYMBOL_TYPE::ESCAPE_CHAR},

    {' ',   SYMBOL_TYPE::SPACE},
    {'\t',  SYMBOL_TYPE::SPACE}
};

/**
 * @brief Token type.
 */
enum class TOKEN_TYPE : int {
  UNKNOWN,
  SECTION,      ///< Section in she_ini_plus
  TYPE,         ///< Type in she_ini_plus
  IDENTIFIERS,  ///< Identifiers,like 'a' in "int a","void a()" in c/c++.
  L_VALUE,      ///< Left value.Equivalent to IDENTIFIERS ↑
  CONSTANTS,    ///< Constants,like '5' in "int a= 5" in c/c++
  R_VALUE,      ///< Right value.Equivalent to CONSTANTS ↑
};

} // she_ini_plus

#endif //SHE_INI_PLUS_SRC_LEXER_SYMBOL_TABLE_H_
