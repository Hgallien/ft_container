#include <iostream>       // std::cout
#include "stack.hpp"         // std::stack
#include "vector.hpp"         // std::vector
#include <deque>          // std::deque

int main ()
{
	std::cout<<" la 1 \n";
	std::deque<int> mydeque (3,100);          // deque with 3 elements
  
	std::cout<<" la 2 \n";
  vector<int> myvector (2,200);        // vector with 2 elements

	std::cout<<" la 3 \n";
  stack<int> first;                    // empty stack

	std::cout<<" la 3.5 \n";
  stack<int,std::deque<int> > second (mydeque);         // stack initialized to copy of deque

	std::cout<<" la 4 \n";
  stack<int,vector<int> > third;  // empty stack using vector
  stack<int,vector<int> > fourth (myvector);

	std::cout<<" la 5 \n";
  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

	std::cout<<" la 6 \n";
  return 0;

	std::cout<<" la 7 \n";
}
