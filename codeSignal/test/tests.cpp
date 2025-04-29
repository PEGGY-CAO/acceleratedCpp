#include <optional>
#include <memory>

#include <catch2/catch.hpp>

#include "utility.hpp"
#include "integer_container_impl.hpp"

/**
 * The test class below includes 10 tests for Level 2.
 *
 * All have the same score.
 * You are not allowed to modify this file, but feel free to read the source code to better understand what is happening in every specific case.
 */
class Level2TestsFixture {
 public:
  Level2TestsFixture() = default;
 protected:

  std::shared_ptr<IntegerContainer> container = std::make_shared<IntegerContainerImpl>();
};

TEST_CASE_METHOD(Level2TestsFixture, "Test level 2 case 01 simple median odd length") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(1) == 1);
    REQUIRE(container->Add(2) == 2);
    REQUIRE(container->Add(5) == 3);
    REQUIRE(container->Add(7) == 4);
    REQUIRE(container->Add(9) == 5);
    REQUIRE(container->GetMedian() == 5);
    REQUIRE(container->Add(11) == 6);
    REQUIRE(container->Add(15) == 7);
    REQUIRE(container->GetMedian() == 7);
  }, 100);
}

TEST_CASE_METHOD(Level2TestsFixture, "Test level 2 case 02 simple median even length") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(10) == 1);
    REQUIRE(container->Add(20) == 2);
    REQUIRE(container->GetMedian() == 10);
    REQUIRE(container->Add(30) == 3);
    REQUIRE(container->Add(40) == 4);
    REQUIRE(container->GetMedian() == 20);
    REQUIRE(container->GetMedian() == 20);
    REQUIRE(container->Add(50) == 5);
    REQUIRE(container->Add(60) == 6);
    REQUIRE(container->Add(70) == 7);
    REQUIRE(container->Add(80) == 8);
    REQUIRE(container->GetMedian() == 40);
  }, 100);
}

TEST_CASE_METHOD(Level2TestsFixture, "Test level 2 case 03 median of empty container") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->GetMedian() == std::nullopt);
    REQUIRE(container->Add(1) == 1);
    REQUIRE(container->GetMedian() == 1);
  }, 100);
}

TEST_CASE_METHOD(Level2TestsFixture, "Test level 2 case 04 median of non sorted container") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(3) == 1);
    REQUIRE(container->Add(2) == 2);
    REQUIRE(container->Add(5) == 3);
    REQUIRE(container->Add(4) == 4);
    REQUIRE(container->Add(1) == 5);
    REQUIRE(container->GetMedian() == 3);
    REQUIRE(container->Add(8) == 6);
    REQUIRE(container->Add(6) == 7);
    REQUIRE(container->Add(7) == 8);
    REQUIRE(container->GetMedian() == 4);
  }, 100);
}

TEST_CASE_METHOD(Level2TestsFixture, "Test level 2 case 05 median of container with duplicates") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(5) == 1);
    REQUIRE(container->Add(3) == 2);
    REQUIRE(container->Add(5) == 3);
    REQUIRE(container->Add(5) == 4);
    REQUIRE(container->Add(10) == 5);
    REQUIRE(container->Add(3) == 6);
    REQUIRE(container->GetMedian() == 5);
    REQUIRE(container->Add(3) == 7);
    REQUIRE(container->Add(3) == 8);
    REQUIRE(container->Add(3) == 9);
    REQUIRE(container->GetMedian() == 3);
  }, 100);
}

TEST_CASE_METHOD(Level2TestsFixture, "Test level 2 case 06 median with deletions") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(30) == 1);
    REQUIRE(container->Add(20) == 2);
    REQUIRE(container->Add(10) == 3);
    REQUIRE(container->GetMedian() == 20);
    REQUIRE(container->Delete(30));
    REQUIRE(container->GetMedian() == 10);
    REQUIRE(container->Delete(10));
    REQUIRE(container->GetMedian() == 20);
    REQUIRE(container->Delete(20));
    REQUIRE(container->GetMedian() == std::nullopt);
  }, 100);
}

TEST_CASE_METHOD(Level2TestsFixture, "Test level 2 case 07 double median and deletions") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->GetMedian() == std::nullopt);
    REQUIRE(container->GetMedian() == std::nullopt);
    REQUIRE(!container->Delete(239));
    REQUIRE(container->GetMedian() == std::nullopt);
    REQUIRE(container->GetMedian() == std::nullopt);
    REQUIRE(container->Add(239) == 1);
    REQUIRE(container->GetMedian() == 239);
    REQUIRE(container->GetMedian() == 239);
    REQUIRE(container->Delete(239));
    REQUIRE(!container->Delete(239));
    REQUIRE(container->GetMedian() == std::nullopt);
    REQUIRE(container->GetMedian() == std::nullopt);
  }, 100);
}

TEST_CASE_METHOD(Level2TestsFixture, "Test level 2 case 08 median of container with negative integers") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->Add(-20) == 1);
    REQUIRE(container->Add(-10) == 2);
    REQUIRE(container->Add(10) == 3);
    REQUIRE(container->Add(20) == 4);
    REQUIRE(container->Add(0) == 5);
    REQUIRE(container->GetMedian() == 0);
    REQUIRE(container->Add(-30) == 6);
    REQUIRE(container->GetMedian() == -10);
    REQUIRE(container->Add(30) == 7);
    REQUIRE(container->GetMedian() == 0);
    REQUIRE(container->Add(40) == 8);
    REQUIRE(container->Add(50) == 9);
    REQUIRE(container->GetMedian() == 10);
  }, 100);
}

TEST_CASE_METHOD(Level2TestsFixture, "Test level 2 case 09 mixed operations 1") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->GetMedian() == std::nullopt);
    REQUIRE(container->Add(5) == 1);
    REQUIRE(container->Add(3) == 2);
    REQUIRE(container->Add(5) == 3);
    REQUIRE(container->Add(7) == 4);
    REQUIRE(container->Add(8) == 5);
    REQUIRE(container->Add(9) == 6);
    REQUIRE(container->GetMedian() == 5);
    REQUIRE(container->Delete(5));
    REQUIRE(container->Delete(8));
    REQUIRE(container->GetMedian() == 5);
    REQUIRE(container->Delete(5));
    REQUIRE(!container->Delete(5));
    REQUIRE(container->GetMedian() == 7);
    REQUIRE(container->Add(5) == 4);
    REQUIRE(container->GetMedian() == 5);
    REQUIRE(container->Delete(5));
    REQUIRE(!container->Delete(5));
    REQUIRE(container->Delete(7));
    REQUIRE(container->Delete(3));
    REQUIRE(container->GetMedian() == 9);
    REQUIRE(container->Delete(9));
    REQUIRE(container->GetMedian() == std::nullopt);
    REQUIRE(!container->Delete(9));
    REQUIRE(container->GetMedian() == std::nullopt);
  }, 100);
}

TEST_CASE_METHOD(Level2TestsFixture, "Test level 2 case 10 mixed operations 2") {
  Utility::CheckTimeout([&]() {
    REQUIRE(container->GetMedian() == std::nullopt);
    REQUIRE(container->Add(1) == 1);
    REQUIRE(container->Add(1) == 2);
    REQUIRE(container->Add(2) == 3);
    REQUIRE(container->Add(2) == 4);
    REQUIRE(container->Add(3) == 5);
    REQUIRE(container->Add(3) == 6);
    REQUIRE(container->Add(4) == 7);
    REQUIRE(container->Add(4) == 8);
    REQUIRE(container->Add(5) == 9);
    REQUIRE(container->Add(5) == 10);
    REQUIRE(container->GetMedian() == 3);
    REQUIRE(container->Delete(1));
    REQUIRE(container->Delete(1));
    REQUIRE(!container->Delete(1));
    REQUIRE(container->GetMedian() == 3);
    REQUIRE(container->Delete(2));
    REQUIRE(container->Delete(2));
    REQUIRE(!container->Delete(2));
    REQUIRE(container->GetMedian() == 4);
    REQUIRE(container->Delete(3));
    REQUIRE(container->Delete(4));
    REQUIRE(container->Delete(5));
    REQUIRE(container->GetMedian() == 4);
  }, 100);
}
