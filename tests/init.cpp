#include "stack.hpp"
#include <catch.hpp>
#include <iostream>
#include <thread>
#include<mutex>
using namespace std;
 
SCENARIO("count", "[count]"){
  stack<int> s;
  s.push(1);
  REQUIRE(s.count()==1);
}

SCENARIO("push", "[push]"){
  stack<int> s;
  s.push(1);
  REQUIRE(s.count()==1);
}

SCENARIO("pop", "[pop]"){
  stack<int> s;
  s.push(1);
  REQUIRE(*(s.pop())==1);	
  REQUIRE(s.count()==0);
}

SCENARIO("prisv", "[prisv]"){
  stack<int> s;
  s.push(1);
  stack<int> s2;
  s2=s;
  REQUIRE(s.count()==1);
}

SCENARIO("empty", "[empty]"){
  stack<int> s1, s2;
  s1.push(1);
  REQUIRE(!s1.empty());
  REQUIRE(s2.empty());
}


SCENARIO("mutex", "[mutex]"){
  stack<int> s1;
  s1.push(1);
  s1.push(2);
  
  thread potok_1(&stack<int>::push, &s1, 3);
  potok_1.join();
  REQUIRE(s1.top()==3);
  thread potok_2(&stack<int>::pop, &s1);
  potok_2.join();
  REQUIRE(s1.top()==2);
}

