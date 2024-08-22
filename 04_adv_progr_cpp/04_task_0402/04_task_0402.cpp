#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <locale.h>
#include <catch2/catch_test_macros.hpp>
#include "04_task_0402.h"

//-------------------------------------------------------------------------------------
TEST_CASE("test Class List", "[List]") {
    SECTION("Testing the PushBack + PopBack functions") {
    List list_1;
    REQUIRE(list_1.Size() == static_cast<unsigned long> (0));
    list_1.PushBack(11);
    list_1.PushBack(22);
    REQUIRE(list_1.PopBack() == 22);
    REQUIRE(list_1.Size() == 1);
  }

  SECTION("Testing the PushFront + PopFront functions") {
    List list_2;
    list_2.PushFront(11);
    list_2.PushFront(33);
    REQUIRE(list_2.Size() == 2);
    REQUIRE(list_2.PopFront() == 33);
    REQUIRE(list_2.Size() == 1);
  }

  SECTION("Testing the PopBack function") {
    List list_3;
    REQUIRE(list_3.PopBack());
  }

  SECTION("Testing the PopFront function") {
    List list_4;
    REQUIRE(list_4.PopFront());
  }
}