#ifndef TEST_MAIN_HPP
#define TEST_MAIN_HPP
#include <iostream>
#include "stack.hpp"
#include <fstream>
template<typename T>
void	print_stack(stack<T> &s,std::ofstream &out)
{
	while (!s.empty())
	{
		out<<s.top()<<" ";
		s.pop();
	}
}
	template <typename T>
void	test_constructor_assignastion(std::ofstream &out)
{
	out<<"////////////Test constructor/////////////////\n";
	stack<T> v_base;
	out<<"Size = "<<v_base.size()<<std::endl;
	out<<"Empty= "<<v_base.empty()<<std::endl;
	print_stack(v_base,out);
}
template<typename T>
void all_comparisons(stack<T> const & a, stack<T> const & b,std::ofstream &out) {
  std::boolalpha(out);
  out << "a == b : " << (a == b) << std::endl;
  out << "a != b : " << (a != b) << std::endl;
  out << "a < b : " << (a < b) << std::endl;
  out << "a > b : " << (a > b) << std::endl;
  out << "a >= b : " << (a >= b) << std::endl;
  out << "a <= b : " << (a <= b) << std::endl;
}

template<typename T>
void test_comparisons(std::ofstream &out) {
  
	stack<T> v1;

	stack<T> v1_b;

	stack<T> v2;
	stack<T> v2_b;
	stack<T> v3;
	stack<T> v3_b;
	for (int i = 0 ; i < 4 ; i++)
	{	
		v1.push(T(i));
		v1_b.push(T(i));
	}
  	for (int i = 0 ; i < 5 ; i++)
	{	
		v2.push(T(i));
	}
for (int i = 0 ; i < 3 ; i++)
	{	
		v2_b.push(T(i));
	}
		v3.push(T(0));
		v3.push(T(1));
		v3.push(T(10));
  		v3.push(T(0));
		v3.push(T(1));
		v3.push(T(1));
  all_comparisons(v1, v1_b,out);
  all_comparisons(v1, v2,out);
  all_comparisons(v1, v2_b,out);
 all_comparisons(v1, v3,out);
  all_comparisons(v1, v3_b,out);
}

template <typename T>
void	test_modifier(std::ofstream &out)
{
	out<<"/////////////////Test modifiers  & access////////////////\n";
	stack<T> v_b;

		out<<"Test push \n";
	for (int i = 0 ; i < 10000 ; i ++)
	{
		v_b.push(T(i));
	}
	out<<"\n";
	print_stack(v_b,out);
	}
#endif 
