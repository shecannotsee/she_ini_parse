//
// Created by shecannotsee on 23-10-12.
//

#ifndef SHE_INI_PARSE_LEXER_DFA_MODEL_H
#define SHE_INI_PARSE_LEXER_DFA_MODEL_H

#include <unordered_map>
#include <provide_hash.h>

namespace she {

namespace lexer_DFA_model {

/********** States ****************************************************************************************************/
enum class states : int {
  S1,S2,S3,REFUSE
};

/********** alphabet **************************************************************************************************/
enum class alphabet : int {
  Q1,Q2,Q3,Q4
};

static std::unordered_map<char, alphabet> cher_table = {
  {'\n',alphabet::Q1},
  {'\\',alphabet::Q2},
  {' ', alphabet::Q3}
};

// convert Character to State
template<typename char_type>
alphabet get_alphabet(char_type input) {
  if (cher_table.find(input) != cher_table.end()) {
    return cher_table[input];
  } else {
    return alphabet::Q4;
  }
}

/********** Transition Function ***************************************************************************************/
static std::unordered_map<std::tuple<int,int>,states> transfer_function = {
  {{static_cast<int>(states::S1),static_cast<int>(alphabet::Q1)},/* -> */states::S3},
  {{static_cast<int>(states::S1),static_cast<int>(alphabet::Q2)},/* -> */states::S2},
  {{static_cast<int>(states::S1),static_cast<int>(alphabet::Q3)},/* -> */states::S1},
  {{static_cast<int>(states::S1),static_cast<int>(alphabet::Q4)},/* -> */states::S1},
  {{static_cast<int>(states::S2),static_cast<int>(alphabet::Q1)},/* -> */states::S1},
  {{static_cast<int>(states::S2),static_cast<int>(alphabet::Q2)},/* -> */states::S1},
  {{static_cast<int>(states::S2),static_cast<int>(alphabet::Q3)},/* -> */states::S2},
  {{static_cast<int>(states::S2),static_cast<int>(alphabet::Q4)},/* -> */states::S1},
};

template<typename char_type>
states transition_status(states now, char_type input) {
  int input_S = static_cast<int>(now);
  int input_Q = static_cast<int>(get_alphabet(input));
  auto key = std::make_tuple(input_S,input_Q);
  if(transfer_function.find(key)!= transfer_function.end())
    return transfer_function[key];
  else {
    return states::REFUSE;
  }
}

/********** init state ************************************************************************************************/
constexpr states start_state = states::S1;

/********** accept state **********************************************************************************************/
constexpr states accept_state = states::S3;

}// lexer_DFA_model

}// ini_parse


#endif //SHE_INI_PARSE_LEXER_DFA_MODEL_H
