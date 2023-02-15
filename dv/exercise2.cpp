#include <cstdint>
#include <bit>

#include <catch2/catch_test_macros.hpp>
#include <VExercise2.h>

using namespace std;

static constexpr uint16_t NUM_OF_ITERS = 100;

struct ReadingRainbow {
  uint16_t value;
  static constexpr uint16_t mask {0x50a};

  void step() {
    uint16_t bits = value & mask;
    value = (value << 1) | (__popcount(bits) & 1);
  }
};

void step(VExercise2& model) {
  model.clk = 1;
  model.eval();
  model.clk = 0;
  model.eval();
}

TEST_CASE("Exercise 2 Test Reset") {
  VExercise2 model;
  model.reset = 1;
  model.init = 0;
  step(model);
  uint16_t result = ~0;
  REQUIRE(model.out == result);

  step(model);
  step(model);
  step(model);
  step(model);
  REQUIRE(model.out == result);

  model.init = 10;
  result = ~10;
  step(model);
  REQUIRE(model.out == result);
  
}

void test_exercise_2_100_iters(uint16_t init) {
  VExercise2 model;
  model.reset = 1;
  model.init = init;
  step(model);
  model.reset = 0;

  ReadingRainbow solution{(uint16_t) ~init};
  for(size_t i = 0; i < NUM_OF_ITERS; ++i) {
    REQUIRE(model.out == solution.value);
    step(model);
    solution.step();
  }

  model.reset = 1;
  step(model);
  REQUIRE(model.out == (uint16_t) ~init);
}

TEST_CASE("Exercise 2 Set starting values") {

  test_exercise_2_100_iters(0);
  test_exercise_2_100_iters((uint16_t) ~0);

  test_exercise_2_100_iters(100);
  test_exercise_2_100_iters(3456);
}

TEST_CASE("Exercise 2 Random starting values") {
  for (size_t i = 0; i < 10; ++i) {
    uint16_t random = rand() % ((uint16_t) ~0 + 1);
    test_exercise_2_100_iters(random);
  }
}