#include "stack.cpp"
#include <catch.hpp>


SCENARIO("count", "[count]"){
  stack<int> s;
  s.push(1);
  REQUIRE(s.count()==1);
}
