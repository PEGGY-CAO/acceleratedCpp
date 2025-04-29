#include <optional>
#include <memory>

#include <catch2/catch.hpp>

#include "utility.hpp"
#include "integer_container_impl.hpp"

/**
 * The test class below includes 10 tests for Level 1.
 *
 * All have the same score.
 * You are not allowed to modify this file, but feel free to read the source code to better understand what is happening in every specific case.
 */
class Level1TestsFixture {
 public:
  Level1TestsFixture() = default;
 protected:

  std::shared_ptr<IntegerContainer> container = std::make_shared<IntegerContainerImpl>();
};

TEST_CASE_METHOD(Level1TestsFixture, "Test level 1 case 01 add two numbers") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(10) == 1);
    REQUIRE(container->Add(100) == 2);
  }, 100);
}

TEST_CASE_METHOD(Level1TestsFixture, "Test level 1 case 02 add many numbers") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(10) == 1);
    REQUIRE(container->Add(9) == 2);
    REQUIRE(container->Add(8) == 3);
    REQUIRE(container->Add(7) == 4);
    REQUIRE(container->Add(6) == 5);
    REQUIRE(container->Add(5) == 6);
    REQUIRE(container->Add(4) == 7);
    REQUIRE(container->Add(3) == 8);
    REQUIRE(container->Add(2) == 9);
    REQUIRE(container->Add(1) == 10);
  }, 100);
}

TEST_CASE_METHOD(Level1TestsFixture, "Test level 1 case 03 delete number") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(10) == 1);
    REQUIRE(container->Add(100) == 2);
    REQUIRE(container->Delete(10));
  }, 100);
}

TEST_CASE_METHOD(Level1TestsFixture, "Test level 1 case 04 delete nonexisting number") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(10) == 1);
    REQUIRE(container->Add(100) == 2);
    REQUIRE(!container->Delete(20));
    REQUIRE(container->Delete(10));
    REQUIRE(!container->Delete(10));
  }, 100);
}

TEST_CASE_METHOD(Level1TestsFixture, "Test level 1 case 05 add and delete same numbers") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(10) == 1);
    REQUIRE(container->Add(10) == 2);
    REQUIRE(container->Add(10) == 3);
    REQUIRE(container->Add(10) == 4);
    REQUIRE(container->Add(10) == 5);
    REQUIRE(container->Delete(10));
    REQUIRE(container->Delete(10));
    REQUIRE(container->Delete(10));
    REQUIRE(container->Delete(10));
    REQUIRE(container->Delete(10));
    REQUIRE(!container->Delete(10));
    REQUIRE(!container->Delete(10));
  }, 100);
}

TEST_CASE_METHOD(Level1TestsFixture, "Test level 1 case 06 add delete several times") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(555) == 1);
    REQUIRE(container->Delete(555));
    REQUIRE(!container->Delete(555));
    REQUIRE(container->Add(555) == 1);
    REQUIRE(container->Delete(555));
    REQUIRE(!container->Delete(555));
  }, 100);
}

TEST_CASE_METHOD(Level1TestsFixture, "Test level 1 case 07 delete in random order") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(10) == 1);
    REQUIRE(container->Add(20) == 2);
    REQUIRE(container->Add(30) == 3);
    REQUIRE(container->Add(40) == 4);
    REQUIRE(container->Add(40) == 5);
    REQUIRE(container->Delete(30));
    REQUIRE(!container->Delete(30));
    REQUIRE(container->Delete(10));
    REQUIRE(!container->Delete(10));
    REQUIRE(container->Delete(40));
    REQUIRE(container->Delete(40));
    REQUIRE(!container->Delete(40));
    REQUIRE(container->Delete(20));
    REQUIRE(!container->Delete(20));
  }, 100);
}

TEST_CASE_METHOD(Level1TestsFixture, "Test level 1 case 08 delete before add") {
  Utility::CheckTimeout([&]() {
    REQUIRE(!container->Delete(1));
    REQUIRE(!container->Delete(2));
    REQUIRE(!container->Delete(3));
    REQUIRE(container->Add(1) == 1);
    REQUIRE(container->Add(2) == 2);
    REQUIRE(container->Add(3) == 3);
    REQUIRE(container->Delete(3));
    REQUIRE(container->Delete(2));
    REQUIRE(container->Delete(1));
    REQUIRE(!container->Delete(3));
    REQUIRE(!container->Delete(2));
    REQUIRE(!container->Delete(1));
  }, 100);
}

TEST_CASE_METHOD(Level1TestsFixture, "Test level 1 case 09 mixed operation 1") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(10) == 1);
    REQUIRE(container->Add(15) == 2);
    REQUIRE(container->Add(20) == 3);
    REQUIRE(container->Add(10) == 4);
    REQUIRE(container->Add(5) == 5);
    REQUIRE(container->Delete(15));
    REQUIRE(container->Delete(20));
    REQUIRE(!container->Delete(20));
    REQUIRE(!container->Delete(0));
    REQUIRE(container->Add(7) == 4);
    REQUIRE(container->Add(9) == 5);
    REQUIRE(container->Delete(7));
    REQUIRE(container->Delete(10));
    REQUIRE(container->Delete(10));
    REQUIRE(!container->Delete(10));
    REQUIRE(!container->Delete(100));
  }, 100);
}

TEST_CASE_METHOD(Level1TestsFixture, "Test level 1 case 10 mixed operation 2") {
  Utility::CheckTimeout([&]() {
    REQUIRE(!container->Delete(6));
    REQUIRE(container->Add(100) == 1);
    REQUIRE(!container->Delete(200));
    REQUIRE(container->Add(500) == 2);
    REQUIRE(!container->Delete(0));
    REQUIRE(container->Add(300) == 3);
    REQUIRE(!container->Delete(1000));
    REQUIRE(container->Add(400) == 4);
    REQUIRE(container->Delete(300));
    REQUIRE(container->Delete(400));
    REQUIRE(container->Delete(100));
    REQUIRE(container->Delete(500));
    REQUIRE(container->Add(1000) == 1);
    REQUIRE(container->Add(100) == 2);
    REQUIRE(container->Add(10) == 3);
    REQUIRE(container->Add(1) == 4);
    REQUIRE(container->Delete(100));
    REQUIRE(!container->Delete(500));
    REQUIRE(!container->Delete(300));
    REQUIRE(!container->Delete(400));
  }, 100);
}
