#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <locale.h>
#include <catch2/catch_test_macros.hpp>
#include "04_task_0401.h"

//-------------------------------------------------------------------------------------
TEST_CASE("test Class List", "[List]") {
  
  SECTION("Testing the Empty + Size functions") {
    List list_1;
    REQUIRE(list_1.Empty() == 1);
    REQUIRE(list_1.Size() == static_cast<unsigned long> (0));
  }

  SECTION ("Testing the Empty + Size + PushFront functions") {
    List list_1;
    list_1.PushFront(11);
    list_1.PushFront(22);
    REQUIRE(list_1.Empty() == 0);
    REQUIRE(list_1.Size() == static_cast<unsigned long> (2));
  }

  SECTION("Testing the Clear functions") {
    List list_1;
    list_1.PushFront(11);
    REQUIRE(list_1.Size() == static_cast<unsigned long> (1));
    list_1.Clear();
    REQUIRE(list_1.Size() == static_cast<unsigned long> (0));
  }
}