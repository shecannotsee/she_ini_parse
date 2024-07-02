//
// Created by shecannotsee on 23-8-1.
//

#ifndef SHE_INI_PLUS_TEST_LEXER_T_CHARACTER_SCANNING_H_
#define SHE_INI_PLUS_TEST_LEXER_T_CHARACTER_SCANNING_H_

#include <lexer/character_scanning.h>

TEST(character_scanning,getchar){
  she_ini_plus::character_scanning scanner("../test_file/t1_disk_io_interface");
  // Adjust the size of the buffer to 5 bytes
  scanner.set_buffer_size(5);

  auto _1 = scanner.getchar();
  EXPECT_EQ(_1.size(),5);
  EXPECT_EQ(_1[0],'1');
  EXPECT_EQ(_1[1],'\n');
  EXPECT_EQ(_1[2],'2');
  EXPECT_EQ(_1[3],'\n');
  EXPECT_EQ(_1[4],'3');

  auto _2 = scanner.getchar();
  EXPECT_EQ(_2.size(),5);
  EXPECT_EQ(_2[0],'\n');
  EXPECT_EQ(_2[1],'4');
  EXPECT_EQ(_2[2],'\n');
  EXPECT_EQ(_2[3],'\n');
  EXPECT_EQ(_2[4],'e');

  auto _3 = scanner.getchar();
  EXPECT_EQ(_3.size(),2);
  EXPECT_EQ(_3[0],'n');
  EXPECT_EQ(_3[1],'d');

  auto space = scanner.getchar();
  EXPECT_EQ(space.size(),0);

};

#endif //SHE_INI_PLUS_TEST_LEXER_T_CHARACTER_SCANNING_H_
