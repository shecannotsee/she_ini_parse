//
// Created by shecannotsee on 23-7-10.
//

#ifndef SHE_INI_PLUS_TEST_T1_DISK_IO_INTERFACE_H_
#define SHE_INI_PLUS_TEST_T1_DISK_IO_INTERFACE_H_

#include <stdio.h>

namespace t1_disk_io_interface {

int main() {
  // 打开文件
  FILE *file = fopen("../test_file/t1_disk_io_interface", "r");
  if (file == NULL) {
    std::cout <<"can not open file.\n";
    return 1;
  }

  // 逐个字符读取并打印
  char c;
  while ((c = fgetc(file)) != EOF) {
    if( c == '\n' ) {
      std::cout << "\\n" << std::endl;
    } else {
      std::cout << c << std::endl;
    }
  }

  // 关闭文件
  fclose(file);

  return 0;
}

} // namespace t1_disk_io_interface

#endif //SHE_INI_PLUS_TEST_T1_DISK_IO_INTERFACE_H_
