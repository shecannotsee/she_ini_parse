//
// Created by shecannotsee on 23-7-10.
//
#include <iostream>
#include "global_test_set.h"
#include "test_example.h"
// test_suite
#include "disk_io/t_read_from_file.h"
#include "lexer/t_character_scanning.h"
#include "lexer/t_matching.h"
#include "lexer/t_token.h"
// easy_test
#include "t1_disk_io_interface.h"

int main() {
  std::cout << YELLOW_COLOR << "Start test " << RESET_COLOR << std::endl;
  constexpr bool easy_test  = false;
  constexpr bool test_suite = true;
  if(easy_test) {
    t1_disk_io_interface::main();
  }

  if(test_suite) {
    testing::InitGoogleTest();

    if (RUN_ALL_TESTS() == 0) {
      std::cout << GREEN_COLOR << "Pass the test." << RESET_COLOR << std::endl;
    } else {
      std::cout << RED_COLOR << "Failed the test." << RESET_COLOR << std::endl;
    }
  }

  return 0;
};