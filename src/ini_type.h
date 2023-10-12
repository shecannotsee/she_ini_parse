//
// Created by shecannotsee on 23-10-10.
//

#ifndef SHE_INI_PARSE_TYPE_H
#define SHE_INI_PARSE_TYPE_H

namespace ini_parse {

enum class lexer_type {
  SECTION_BEGIN = '[',
  SECTION_END   = ']',
  TYPE_CONVERSION = '=',

  NOTE = '#',
  LINE_BREAK = '\n',

  ESCAPE = '\\',
  VALUE = 0
};

}

#endif //SHE_INI_PARSE_TYPE_H
