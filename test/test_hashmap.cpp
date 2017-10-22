#include <gtest/gtest.h>
#include "hashmap.h"

TEST(HashMap, hashMapTest1)
{
    exemplar::HashMap<int, string> map;
    map.set(0, "adam");
    map.set(1, "jennah");
    map.set(2, "ada");
    map.set(100, "monkey");
    ASSERT_TRUE(map.get(0) == "adam" &&
                map.get(1) == "jennah" &&
                map.get(2) == "ada" &&
                map.get(100) == "monkey");
}

TEST(HashMap, hashMapTest2)
{
    exemplar::HashMap<string, string> map;
    map.set("adam", "daddy");
    map.set("jennah", "mommy");
    map.set("ada", "baby");
    map.set("ripley", "doggie");
    ASSERT_TRUE(map.get("adam") == "daddy" &&
                map.get("jennah") == "mommy" &&
                map.get("ada") == "baby" &&
                map.get("ripley") == "doggie");
}
