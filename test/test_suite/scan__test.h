//
// Created by shecannotsee on 23-10-10.
//

#ifndef SHE_INI_PARSE_SCAN__TEST_H
#define SHE_INI_PARSE_SCAN__TEST_H

#include <scan.h>

TEST(scan__test,constructors) {
  EXPECT_NO_THROW(ini_parse::scan scanning("../resource/placeholder.ini"));
  ASSERT_THROW(ini_parse::scan scanning("no_this_file"), std::runtime_error);
}

TEST(scan__test, get_char) {
  ini_parse::scan scanning("../resource/placeholder.ini");
  auto buffer = scanning.get();
  const std::string content = "[real_section] #we call this line section\nreal_key = real_value";
  for (int i=0; i<buffer.size() || i<content.size(); ++i) {
    ASSERT_EQ(buffer[i],content[i]);
  }

}

#endif //SHE_INI_PARSE_SCAN__TEST_H
