#include <iostream>       // std::cout
#include "stack.hpp"         // std::stack
#include "vector.hpp"         // std::vector
#include <deque>          // std::deque

#include <iostream>

#include <chrono>

#include <deque>
#include <memory>
#include "vector.hpp"
#include "test_main.hpp"
#include "stl_test_main.hpp"

#include <fstream>
struct A {
	A() {
		m = new int();
	}
	A(const int a) {

		m = new int();
		*m =a;
	}
	A(A const & x) {

		m = new int();
		*m = *x.m;
	}
	A & operator=(A const & x) {

		*m = *x.m;
		return *this;
	}
	A & operator=(int n) {

		*m = n;
		return *this;
	}
	~A() {
		delete m;
	}
	friend bool operator==(A const &base,A const &cpy)
	{
		if (*(cpy.m) == *(base.m))
			return 1;
		else
			return 0;
	}
	friend bool operator<(A const &base,A const &cpy)
	{
		if (*(base.m) < *(cpy.m))
			return 1;
		else
			return 0;
	}
	friend bool operator>(A const &base,A const &cpy)
	{
		if (*(base.m) > *(cpy.m))
			return 1;
		else
			return 0;
	}
	friend bool operator!=(A const &base,A const &cpy)
	{
			return !(base == cpy );
	}
	friend std::ostream & operator<<(std::ostream & os, A const & a) {
		return os << *a.m;
	}

	int *m;
};

int main ()
{
	std::ofstream std_file;
	std::ofstream mine_file;
	clock_t t_start_stl;
	clock_t t_start_mine;
	
	std_file.open("std_out", std::ios::out);
	mine_file.open("mine_out", std::ios::out);
	std_file<<"TEST INT\n";

	 t_start_stl = clock();
	 stl_test_constructor_assignastion<int>(std_file);
	 stl_test_modifier<int>(std_file);
	 stl_test_comparisons<int>(std_file);
	std_file<<"TEST STRUCT A\n";
	stl_test_constructor_assignastion<A>(std_file);
	 stl_test_modifier<A>(std_file);
	 stl_test_comparisons<A>(std_file);

	 t_start_stl = clock() - t_start_stl;
	mine_file<<"TEST INT\n";

	 t_start_mine = clock();
	 test_constructor_assignastion<int>(mine_file);
	 test_modifier<int>(mine_file);
	 test_comparisons<int>(mine_file);
//
	mine_file<<"TEST STRUCT A\n";
	test_constructor_assignastion<A>(mine_file);
	 test_modifier<A>(mine_file);
	 test_comparisons<A>(mine_file);
//
	 t_start_mine = clock() - t_start_mine;
	std::cout<<"my timing = "<< ((float)t_start_mine) / CLOCKS_PER_SEC<<" timing stl ="<<((float)t_start_stl) / CLOCKS_PER_SEC<<" difference = "<<((float)t_start_mine) / CLOCKS_PER_SEC - ((float)t_start_stl) / CLOCKS_PER_SEC<<std::endl;
	 std_file.close();
	mine_file.close();
}
