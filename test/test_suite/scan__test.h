//
// Created by shecannotsee on 23-10-10.
//

#ifndef SHE_INI_PARSE_SCAN__TEST_H
#define SHE_INI_PARSE_SCAN__TEST_H

#include <scan.h>

TEST(scan__test,constructors) {
  EXPECT_NO_THROW(she::scan scanning("../resource/placeholder.ini"));
  ASSERT_THROW(she::scan scanning("no_this_file"), std::runtime_error);
}

TEST(scan__test, get_char) {
  she::scan scanning("../resource/placeholder.ini");
  auto buffer = scanning.get();
  const std::string content = "[real_section] #we call this line section\nreal_key = real_value";
  for (int i=0; i<buffer.size() || i<content.size(); ++i) {
    ASSERT_EQ(buffer[i],content[i])<<"should is:"<<content[i]<<",but file is:"<< buffer[i]<<std::endl;
  }

}

#endif //SHE_INI_PARSE_SCAN__TEST_H
