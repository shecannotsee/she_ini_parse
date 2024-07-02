//
// Created by shecannotsee on 23-7-27.
//

#ifndef SHE_INI_PLUS_TEST_DISK_IO_T_READ_FROM_FILE_H_
#define SHE_INI_PLUS_TEST_DISK_IO_T_READ_FROM_FILE_H_

#include <disk_io/read_from_file.h>

TEST(read_from_file,get){
  using rff = she_ini_plus::read_from_file;
  rff r("../test_file/t1_disk_io_interface");
  EXPECT_EQ(rff::valid_data(r.get()),'1')<<"value:"<<rff::valid_data(r.get());
  EXPECT_EQ(rff::valid_data(r.get()),'\n')<<"value:"<<rff::valid_data(r.get());

  EXPECT_EQ(rff::valid_data(r.get()),'2')<<"value:"<<rff::valid_data(r.get());
  EXPECT_EQ(rff::valid_data(r.get()),'\n')<<"value:"<<rff::valid_data(r.get());

  EXPECT_EQ(rff::valid_data(r.get()),'3')<<"value:"<<rff::valid_data(r.get());
  EXPECT_EQ(rff::valid_data(r.get()),'\n')<<"value:"<<rff::valid_data(r.get());

  EXPECT_EQ(rff::valid_data(r.get()),'4')<<"value:"<<rff::valid_data(r.get());
  EXPECT_EQ(rff::valid_data(r.get()),'\n')<<"value:"<<rff::valid_data(r.get());

  EXPECT_EQ(rff::valid_data(r.get()),'\n')<<"value:"<<rff::valid_data(r.get());

  EXPECT_EQ(rff::valid_data(r.get()),'e')<<"value:"<<rff::valid_data(r.get());
  EXPECT_EQ(rff::valid_data(r.get()),'n')<<"value:"<<rff::valid_data(r.get());
  EXPECT_EQ(rff::valid_data(r.get()),'d')<<"value:"<<rff::valid_data(r.get());
  EXPECT_EQ(rff::data_is_valid(r.get()), false)<<"value:"<<rff::data_is_valid(r.get());
};

#endif //SHE_INI_PLUS_TEST_DISK_IO_T_READ_FROM_FILE_H_
