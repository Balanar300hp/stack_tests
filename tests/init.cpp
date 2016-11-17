 #include "stack.hpp"		  #include "stack.hpp"
  #include <catch.hpp>		  #include <catch.hpp>
  #include <iostream>		  #include <iostream>
 +#include <string>
 +#include <fstream>
  using namespace std;		  using namespace std;
   		   
 -SCENARIO("count", "[count]"){		 +SCENARIO("count111", "[count1111]"){
 -  stack<int> s;		 +  B obj("names.txt");
 -  s.push(1);		 + ifstream file("sort.txt");
 -  REQUIRE(s.count()==1);		 + ifstream out("out.txt");
 -}		 + bool p=true;
 -		 + string s1,s2;
 -SCENARIO("push", "[push]"){		 + while (!file.eof()&&!out.eof()){
 -  stack<int> s;		 + getline(file,s1);
 -  s.push(1);		 +  getline(out,s2);
 -  REQUIRE(s.count()==1);		 +  if (s1!=s2){
 -		 +  p=false;
 -}		 +   break;
 -		 +  }
 -SCENARIO("top", "[top]"){		 + }
 -  stack<int> s;		 +  file.close();
 -  s.push(1);		 + out.close();
 -  s.push(2);		 +  REQUIRE(p==true);
 -  s.push(3);		
 -  s.pop();		
 -		
 -  REQUIRE(s.top()==2);		
 -}		
 -SCENARIO("operprisv", "[operprisv]"){		
 -  stack<int> s1;		
 -  s1.push(1);		
 -  stack<int> s2;		
 -  s2=s1;		
 -  REQUIRE(s1.count()==s2.count());		
 -}		
 -		
 -SCENARIO("const", "[constr]"){		
 -  stack<int> s1;		
 -  s1.push(1);		
 -  stack<int> s2=s1;		
 -  REQUIRE(s1.count()==s2.count());		
 -}		
 -		
 -SCENARIO("empty", "[empty]"){		
 -  stack<int> s1;		
 -  s1.push(1);		
 -  REQUIRE(s1.empty()==false);		
 -}		
 -		
 -SCENARIO("empty2", "[empty2]"){		
 -  stack<int> s1;		
 -  s1.push(1);		
 -  s1.pop();		
 -  REQUIRE(s1.empty()==true);		
 -}		
 -		
 -SCENARIO("empty3", "[empty3]"){		
 -  stack<int> s1;		
 -  s1.push(1);		
 -  s1.push(2);		
 -  s1.pop();		
 -  s1.top();		
 -  		
 -  REQUIRE(s1.empty()==false);		
  }
