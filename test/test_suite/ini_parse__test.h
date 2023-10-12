//
// Created by shecannotsee on 23-10-13.
//

#ifndef SHE_INI_PARSE_INI_PARSE__TEST_H
#define SHE_INI_PARSE_INI_PARSE__TEST_H

#include <ini_parse.h>

TEST(ini_parse__test, get_all_section) {
  she::ini_parse entity("../resource/parse_test.ini");
  auto sections = entity.get_all_section();
  ASSERT_EQ(sections[0], "s1");
  ASSERT_EQ(sections[1], "s2");
  ASSERT_EQ(sections[2], "s3");
  ASSERT_EQ(sections[3], "s4");
  ASSERT_EQ(sections[4], "s5");
  ASSERT_EQ(sections[5], "s6");
  ASSERT_EQ(sections[6], "s7");
  ASSERT_EQ(sections[7], "s8");
  ASSERT_EQ(sections[8], "s9");
  ASSERT_EQ(sections[9], "s10");
}

TEST(ini_parse__test, get_all_key) {
  she::ini_parse entity("../resource/parse_test.ini");
  auto sections = entity.get_all_section();
  auto key_from_s1  = entity.get_all_key("s1"); {
    ASSERT_EQ(key_from_s1[0],"k1");
  }
  auto key_from_s2  = entity.get_all_key("s2"); {
    ASSERT_EQ(key_from_s2[0],"k1");
    ASSERT_EQ(key_from_s2[1],"k2");
  }
  auto key_from_s3  = entity.get_all_key("s3"); {
    ASSERT_EQ(key_from_s3[0],"k1");
    ASSERT_EQ(key_from_s3[1],"k2");
    ASSERT_EQ(key_from_s3[2],"k3");
  }
  auto key_from_s4  = entity.get_all_key("s4"); {
    ASSERT_EQ(key_from_s4[0],"k1");
    ASSERT_EQ(key_from_s4[1],"k2");
    ASSERT_EQ(key_from_s4[2],"k3");
    ASSERT_EQ(key_from_s4[3],"k4");
  }
  auto key_from_s5  = entity.get_all_key("s5"); {
    ASSERT_EQ(key_from_s5[0],"k1");
    ASSERT_EQ(key_from_s5[1],"k2");
    ASSERT_EQ(key_from_s5[2],"k3");
    ASSERT_EQ(key_from_s5[3],"k4");
    ASSERT_EQ(key_from_s5[4],"k5");
  }
  auto key_from_s6  = entity.get_all_key("s6"); {
    ASSERT_EQ(key_from_s6[0],"k1");
    ASSERT_EQ(key_from_s6[1],"k2");
    ASSERT_EQ(key_from_s6[2],"k3");
    ASSERT_EQ(key_from_s6[3],"k4");
    ASSERT_EQ(key_from_s6[4],"k5");
    ASSERT_EQ(key_from_s6[5],"k6");
  }
  auto key_from_s7  = entity.get_all_key("s7"); {
    ASSERT_EQ(key_from_s7[0],"k1");
    ASSERT_EQ(key_from_s7[1],"k2");
    ASSERT_EQ(key_from_s7[2],"k3");
    ASSERT_EQ(key_from_s7[3],"k4");
    ASSERT_EQ(key_from_s7[4],"k5");
    ASSERT_EQ(key_from_s7[5],"k6");
    ASSERT_EQ(key_from_s7[6],"k7");
  }
  auto key_from_s8  = entity.get_all_key("s8"); {
    ASSERT_EQ(key_from_s8[0],"k1");
    ASSERT_EQ(key_from_s8[1],"k2");
    ASSERT_EQ(key_from_s8[2],"k3");
    ASSERT_EQ(key_from_s8[3],"k4");
    ASSERT_EQ(key_from_s8[4],"k5");
    ASSERT_EQ(key_from_s8[5],"k6");
    ASSERT_EQ(key_from_s8[6],"k7");
    ASSERT_EQ(key_from_s8[7],"k8");
  }
  auto key_from_s9  = entity.get_all_key("s9"); {
    ASSERT_EQ(key_from_s9[0],"k1");
    ASSERT_EQ(key_from_s9[1],"k2");
    ASSERT_EQ(key_from_s9[2],"k3");
    ASSERT_EQ(key_from_s9[3],"k4");
    ASSERT_EQ(key_from_s9[4],"k5");
    ASSERT_EQ(key_from_s9[5],"k6");
    ASSERT_EQ(key_from_s9[6],"k7");
    ASSERT_EQ(key_from_s9[7],"k8");
    ASSERT_EQ(key_from_s9[8],"k9");
  }
  auto key_from_s10 = entity.get_all_key("s10"); {
    ASSERT_EQ(key_from_s10[0],"k1");
    ASSERT_EQ(key_from_s10[1],"k2");
    ASSERT_EQ(key_from_s10[2],"k3");
    ASSERT_EQ(key_from_s10[3],"k4");
    ASSERT_EQ(key_from_s10[4],"k5");
    ASSERT_EQ(key_from_s10[5],"k6");
    ASSERT_EQ(key_from_s10[6],"k7");
    ASSERT_EQ(key_from_s10[7],"k8");
    ASSERT_EQ(key_from_s10[9],"k10");
  }
}

TEST(ini_parse__test, get_kvp) {
  she::ini_parse entity("../resource/parse_test.ini");
  auto sections = entity.get_all_section();
  auto key_from_s1  = entity.get_kvp("s1"); {
    ASSERT_EQ(key_from_s1[0].key,"k1");
    ASSERT_EQ(key_from_s1[0].value,"v1");

  }
  auto key_from_s2  = entity.get_kvp("s2"); {
    ASSERT_EQ(key_from_s2[0].key,"k1");
    ASSERT_EQ(key_from_s2[0].value,"v1");
    ASSERT_EQ(key_from_s2[1].key,"k2");
    ASSERT_EQ(key_from_s2[1].value,"v2");
  }
  auto key_from_s3  = entity.get_kvp("s3"); {
    ASSERT_EQ(key_from_s3[0].key,"k1");
    ASSERT_EQ(key_from_s3[0].value,"v1");
    ASSERT_EQ(key_from_s3[1].key,"k2");
    ASSERT_EQ(key_from_s3[1].value,"v2");
    ASSERT_EQ(key_from_s3[2].key,"k3");
    ASSERT_EQ(key_from_s3[2].value,"v3");
  }
  auto key_from_s4  = entity.get_kvp("s4"); {
    ASSERT_EQ(key_from_s4[0].key,"k1");
    ASSERT_EQ(key_from_s4[0].value,"v1");
    ASSERT_EQ(key_from_s4[1].key,"k2");
    ASSERT_EQ(key_from_s4[1].value,"v2");
    ASSERT_EQ(key_from_s4[2].key,"k3");
    ASSERT_EQ(key_from_s4[2].value,"v3");
    ASSERT_EQ(key_from_s4[3].key,"k4");
    ASSERT_EQ(key_from_s4[3].value,"v4");
  }
  auto key_from_s5  = entity.get_kvp("s5"); {
    ASSERT_EQ(key_from_s5[0].key,"k1");
    ASSERT_EQ(key_from_s5[0].value,"v1");
    ASSERT_EQ(key_from_s5[1].key,"k2");
    ASSERT_EQ(key_from_s5[1].value,"v2");
    ASSERT_EQ(key_from_s5[2].key,"k3");
    ASSERT_EQ(key_from_s5[2].value,"v3");
    ASSERT_EQ(key_from_s5[3].key,"k4");
    ASSERT_EQ(key_from_s5[3].value,"v4");
    ASSERT_EQ(key_from_s5[4].key,"k5");
    ASSERT_EQ(key_from_s5[4].value,"v5");
  }
  auto key_from_s6  = entity.get_kvp("s6"); {
    ASSERT_EQ(key_from_s6[0].key,"k1");
    ASSERT_EQ(key_from_s6[0].value,"v1");
    ASSERT_EQ(key_from_s6[1].key,"k2");
    ASSERT_EQ(key_from_s6[1].value,"v2");
    ASSERT_EQ(key_from_s6[2].key,"k3");
    ASSERT_EQ(key_from_s6[2].value,"v3");
    ASSERT_EQ(key_from_s6[3].key,"k4");
    ASSERT_EQ(key_from_s6[3].value,"v4");
    ASSERT_EQ(key_from_s6[4].key,"k5");
    ASSERT_EQ(key_from_s6[4].value,"v5");
    ASSERT_EQ(key_from_s6[5].key,"k6");
    ASSERT_EQ(key_from_s6[5].value,"v6");
  }
  auto key_from_s7  = entity.get_kvp("s7"); {
    ASSERT_EQ(key_from_s7[0].key,"k1");
    ASSERT_EQ(key_from_s7[0].value,"v1");
    ASSERT_EQ(key_from_s7[1].key,"k2");
    ASSERT_EQ(key_from_s7[1].value,"v2");
    ASSERT_EQ(key_from_s7[2].key,"k3");
    ASSERT_EQ(key_from_s7[2].value,"v3");
    ASSERT_EQ(key_from_s7[3].key,"k4");
    ASSERT_EQ(key_from_s7[3].value,"v4");
    ASSERT_EQ(key_from_s7[4].key,"k5");
    ASSERT_EQ(key_from_s7[4].value,"v5");
    ASSERT_EQ(key_from_s7[5].key,"k6");
    ASSERT_EQ(key_from_s7[5].value,"v6");
    ASSERT_EQ(key_from_s7[6].key,"k7");
    ASSERT_EQ(key_from_s7[6].value,"v7");
  }
  auto key_from_s8  = entity.get_kvp("s8"); {
    ASSERT_EQ(key_from_s8[0].key,"k1");
    ASSERT_EQ(key_from_s8[0].value,"v1");
    ASSERT_EQ(key_from_s8[1].key,"k2");
    ASSERT_EQ(key_from_s8[1].value,"v2");
    ASSERT_EQ(key_from_s8[2].key,"k3");
    ASSERT_EQ(key_from_s8[2].value,"v3");
    ASSERT_EQ(key_from_s8[3].key,"k4");
    ASSERT_EQ(key_from_s8[3].value,"v4");
    ASSERT_EQ(key_from_s8[4].key,"k5");
    ASSERT_EQ(key_from_s8[4].value,"v5");
    ASSERT_EQ(key_from_s8[5].key,"k6");
    ASSERT_EQ(key_from_s8[5].value,"v6");
    ASSERT_EQ(key_from_s8[6].key,"k7");
    ASSERT_EQ(key_from_s8[6].value,"v7");
    ASSERT_EQ(key_from_s8[7].key,"k8");
    ASSERT_EQ(key_from_s8[7].value,"v8");
  }
  auto key_from_s9  = entity.get_kvp("s9"); {
    ASSERT_EQ(key_from_s9[0].key,"k1");
    ASSERT_EQ(key_from_s9[0].value,"v1");
    ASSERT_EQ(key_from_s9[1].key,"k2");
    ASSERT_EQ(key_from_s9[1].value,"v2");
    ASSERT_EQ(key_from_s9[2].key,"k3");
    ASSERT_EQ(key_from_s9[2].value,"v3");
    ASSERT_EQ(key_from_s9[3].key,"k4");
    ASSERT_EQ(key_from_s9[3].value,"v4");
    ASSERT_EQ(key_from_s9[4].key,"k5");
    ASSERT_EQ(key_from_s9[4].value,"v5");
    ASSERT_EQ(key_from_s9[5].key,"k6");
    ASSERT_EQ(key_from_s9[5].value,"v6");
    ASSERT_EQ(key_from_s9[6].key,"k7");
    ASSERT_EQ(key_from_s9[6].value,"v7");
    ASSERT_EQ(key_from_s9[7].key,"k8");
    ASSERT_EQ(key_from_s9[7].value,"v8");
    ASSERT_EQ(key_from_s9[8].key,"k9");
    ASSERT_EQ(key_from_s9[8].value,"v9");
  }
  auto key_from_s10 = entity.get_kvp("s10"); {
    ASSERT_EQ(key_from_s10[0].key,"k1");
    ASSERT_EQ(key_from_s10[0].value,"v1");
    ASSERT_EQ(key_from_s10[1].key,"k2");
    ASSERT_EQ(key_from_s10[1].value,"v2");
    ASSERT_EQ(key_from_s10[2].key,"k3");
    ASSERT_EQ(key_from_s10[2].value,"v3");
    ASSERT_EQ(key_from_s10[3].key,"k4");
    ASSERT_EQ(key_from_s10[3].value,"v4");
    ASSERT_EQ(key_from_s10[4].key,"k5");
    ASSERT_EQ(key_from_s10[4].value,"v5");
    ASSERT_EQ(key_from_s10[5].key,"k6");
    ASSERT_EQ(key_from_s10[5].value,"v6");
    ASSERT_EQ(key_from_s10[6].key,"k7");
    ASSERT_EQ(key_from_s10[6].value,"v7");
    ASSERT_EQ(key_from_s10[7].key,"k8");
    ASSERT_EQ(key_from_s10[7].value,"v8");
    ASSERT_EQ(key_from_s10[8].key,"k9");
    ASSERT_EQ(key_from_s10[8].value,"v9");
    ASSERT_EQ(key_from_s10[9].key,"k10");
    ASSERT_EQ(key_from_s10[9].value,"v10");
  }
}

TEST(ini_parse__test, get) {
  she::ini_parse entity("../resource/parse_test.ini");
  ASSERT_EQ(entity.get("s1", "k1"), "v1");

  ASSERT_EQ(entity.get("s2", "k1"), "v1");
  ASSERT_EQ(entity.get("s2", "k2"), "v2");

  ASSERT_EQ(entity.get("s3", "k1"), "v1");
  ASSERT_EQ(entity.get("s3", "k2"), "v2");
  ASSERT_EQ(entity.get("s3", "k3"), "v3");

  ASSERT_EQ(entity.get("s4", "k1"), "v1");
  ASSERT_EQ(entity.get("s4", "k2"), "v2");
  ASSERT_EQ(entity.get("s4", "k3"), "v3");
  ASSERT_EQ(entity.get("s4", "k4"), "v4");

  ASSERT_EQ(entity.get("s5", "k1"), "v1");
  ASSERT_EQ(entity.get("s5", "k2"), "v2");
  ASSERT_EQ(entity.get("s5", "k3"), "v3");
  ASSERT_EQ(entity.get("s5", "k4"), "v4");
  ASSERT_EQ(entity.get("s5", "k5"), "v5");

  ASSERT_EQ(entity.get("s6", "k1"), "v1");
  ASSERT_EQ(entity.get("s6", "k2"), "v2");
  ASSERT_EQ(entity.get("s6", "k3"), "v3");
  ASSERT_EQ(entity.get("s6", "k4"), "v4");
  ASSERT_EQ(entity.get("s6", "k5"), "v5");
  ASSERT_EQ(entity.get("s6", "k6"), "v6");

  ASSERT_EQ(entity.get("s7", "k1"), "v1");
  ASSERT_EQ(entity.get("s7", "k2"), "v2");
  ASSERT_EQ(entity.get("s7", "k3"), "v3");
  ASSERT_EQ(entity.get("s7", "k4"), "v4");
  ASSERT_EQ(entity.get("s7", "k5"), "v5");
  ASSERT_EQ(entity.get("s7", "k6"), "v6");
  ASSERT_EQ(entity.get("s7", "k7"), "v7");

  ASSERT_EQ(entity.get("s8", "k1"), "v1");
  ASSERT_EQ(entity.get("s8", "k2"), "v2");
  ASSERT_EQ(entity.get("s8", "k3"), "v3");
  ASSERT_EQ(entity.get("s8", "k4"), "v4");
  ASSERT_EQ(entity.get("s8", "k5"), "v5");
  ASSERT_EQ(entity.get("s8", "k6"), "v6");
  ASSERT_EQ(entity.get("s8", "k7"), "v7");
  ASSERT_EQ(entity.get("s8", "k8"), "v8");

  ASSERT_EQ(entity.get("s9", "k1"), "v1");
  ASSERT_EQ(entity.get("s9", "k2"), "v2");
  ASSERT_EQ(entity.get("s9", "k3"), "v3");
  ASSERT_EQ(entity.get("s9", "k4"), "v4");
  ASSERT_EQ(entity.get("s9", "k5"), "v5");
  ASSERT_EQ(entity.get("s9", "k6"), "v6");
  ASSERT_EQ(entity.get("s9", "k7"), "v7");
  ASSERT_EQ(entity.get("s9", "k8"), "v8");
  ASSERT_EQ(entity.get("s9", "k9"), "v9");

  ASSERT_EQ(entity.get("s10", "k1"), "v1");
  ASSERT_EQ(entity.get("s10", "k2"), "v2");
  ASSERT_EQ(entity.get("s10", "k3"), "v3");
  ASSERT_EQ(entity.get("s10", "k4"), "v4");
  ASSERT_EQ(entity.get("s10", "k5"), "v5");
  ASSERT_EQ(entity.get("s10", "k6"), "v6");
  ASSERT_EQ(entity.get("s10", "k7"), "v7");
  ASSERT_EQ(entity.get("s10", "k8"), "v8");
  ASSERT_EQ(entity.get("s10", "k9"), "v9");
  ASSERT_EQ(entity.get("s10", "k10"), "v10");
}

#endif //SHE_INI_PARSE_INI_PARSE__TEST_H
