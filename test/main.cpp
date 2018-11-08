#define CATCH_CONFIG_RUNNER
#include "catch2/catch.hpp"

#include <vector>

TEST_CASE("Test framework works", "[unit]") { CHECK('a' < 'b'); }

TEST_CASE("") {}

int main(int argc, char **argv) {
  const int res = Catch::Session().run(argc, argv);
  return res;
}
