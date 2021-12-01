#include <iostream>

#include <vector>

#include <chrono>

#include <deque>
#include <memory>
#include "vector.hpp"
#include "test_main.hpp"
#include "stl_test_main.hpp"

template <typename T>
void	test_modifier();
template <class T>
void printElem(T &elem) {
	std::cout << elem << " ";
}
template <class Iterator>
void iter(Iterator begin, Iterator end, void (*f)(typename Iterator::value_type&)) {
	for (Iterator it = begin; it != end; ++it) {
		f(*it);
	}
}
	template <typename T>
void print_container_nl(vector<T> v)
{
	// (void)v;
	std::cout<<"priny\n";
	for(unsigned int i = 0; i < v.size(); i++)
	{

		std::cout<<v[i]<<" ";
	}

	std::cout<<"prin2\n";
	std::cout<<"\n";
}

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

template <typename T>
void test_with(T (&array10)[10], T (&array7)[7]) {
	vector<T> vect;
	// push_back
	for (int i = 0; i < 10; i++) {
		std::cout<<"ici" <<i<<" "<<array10[i]<<std::endl; 
		vect.push_back(array10[i]);

		std::cout<<"la " <<i<<std::endl; 
		std::cout << vect.size() << std::endl;
		std::cout << vect.back() << std::endl;
	}
	// print_container_nl(vect);
	// //
	// // //insert iterator
	(void)array7;
	// // //
	std::cout<<"toncard 2\n";
	vect.insert(vect.begin() +5, array7, array7+3);
	print_container_nl(vect);
	std::cout<<"tamere \n";

	// insert 1
	typename vector<T>::iterator it = vect.insert(vect.begin(), array7[3]);
	// //
	std::cout<<"tamere 1\n";
	std::cout << *it << std::endl;

	std::cout<<"tamere 2\n";
	std::cout << it - vect.begin() << std::endl;
	std::cout<<"tamere 3\n";
	*it = array7[4];

	std::cout<<"tamere 4\n";
	// insert range
	vect.insert(vect.end() - 1, array7[5]);
	std::cout<<"tamere 5\n";
	print_container_nl(vect);
	vect.insert(vect.begin() + 8, 6, array7[5]);

	std::cout<<"tamere 6 \n";
	print_container_nl(vect);

	std::cout<<"tamere 6.25 \n";
	// pop_back
	for (int i = 0; i < 5; i++) {
		std::cout<<"tamere 6.5 \n";
		vect.pop_back();
		std::cout << "vect.back() = " << vect.back() << std::endl;
		std::cout << "vect.size() = " << vect.size() << std::endl;
	}

	std::cout<<"tamere 7 \n";
	print_container_nl(vect);

	// erase, clear
	vect.clear();
}

template <typename T>
void test_erase(T (&array10)[10]) {
	vector<T> vect(array10, array_end(array10));

	vect.erase(vect.begin() + 2);
	print_container_nl(vect);
	vect.erase(vect.begin() + 1, vect.begin() + 4);
	print_container_nl(vect);
}


template <typename T>
void test_assign(T (&array10)[10]) {
	vector<T> vect;
	std::cout<<"assign1\n";
	vect.assign(array10, array10 + 10);
	std::cout << "vect.size() = " << vect.size() << std::endl;
	std::cout<<"assign123212\n";
	for(unsigned int i = 0; i < vect.size(); i++)
	{
		std::cout<<"\n";
		std::cout<<vect[i]<<" ";
	}
	print_container_nl(vect);

	std::cout<<"assign2\n";
	vect.assign(array10, array10 + 5);
	std::cout << "vect.size() = " << vect.size() << std::endl;
	print_container_nl(vect);
	//
	std::cout<<"assign3\n";
	vect.assign(100, array10[0]);
	std::cout << "vect.size() = " << vect.size() << std::endl;
	print_container_nl(vect);

	std::cout<<"assign4\n";
	vect.assign(5, array10[1]);
	std::cout << "vect.size() = " << vect.size() << std::endl;
	print_container_nl(vect);
	std::cout<<"assign5\n";
}

template <typename T>
void test_swap(T (&array10)[10], T (&array7)[7]) {
	vector<T> vect10;
	vector<T> vect7;

	vect10.assign(array10, array10 + 10);
	vect7.assign(array7, array7 + 7);
	print_container_nl(vect10);
	print_container_nl(vect7);
	std::cout << "Swapping" << std::endl;
	vect10.swap(vect7);
	print_container_nl(vect10);
	print_container_nl(vect7);
}

int main() {
	// std::cout << "Test on vector<int>" << std::endl;
	// int array10_int[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// int array7_int[7] = {111, 222, 333, 444, 555, 666, 777};
	// test_with<int>(array10_int, array7_int);
	// test_assign<int>(array10_int);
	// test_swap<int>(array10_int, array7_int);
	// std::deque<int> s;
	// s.push_back(1);
	// s.push_back(1);
	// s.push_back(1);
	// s.push_back(1);
	// vector<int> test2;
	// test2.push_back(4);
	//
	// test2.push_back(4);
	// test2.push_back(4);
	// test2.push_back(4);
	// vector<int> test_enable(test2.begin(),test2.end());
	// std::cout << std::endl;
	//
	// std::cout << "Test on vector<A>" << std::endl;
	// A array10_A[10];
	// for (int i = 0; i < 10; i++)
	// {
	// array10_A[i] = array10_int[i];
	// }
	// A array7_A[7];
	// for (int i = 0; i < 7; i++) array7_A[i] = array7_int[i];
	//
	// std::cout << "Test on with" << std::endl;
	// test_with<A>(array10_A, array7_A);
	//
	// std::cout << "Test on assign" << std::endl;
	// test_assign<A>(array10_A);
	//
	// std::cout << "Test on swap" << std::endl;
	// test_swap<A>(array10_A, array7_A);
	//
	// vector<int> test_cp(10,10);
	//
	// vector<char> test_c(10,'a');
	// vector<int>::const_iterator it_c(test_cp.begin() + 1);
	// vector<int>  map_c;
	// vector<int> const map_test;
	//
	// vector<int>::const_iterator it_c;
	// vector<int>::iterator it;
	// it_c = map_c.begin();
	// it_c= it;
	// it_c = map_test.begin();
	//
	// std::vector<int> v;
	// std::vector<int>::iterator it3 = v.begin();
	// std::vector<int>::const_iterator it4 = v.begin();
	// // it3 = it4;
	// it4=it3;
	std::ofstream std_file;
	std::ofstream mine_file;
	clock_t t_start_stl;
	clock_t t_start_mine;
	
	std_file.open("std_out", std::ios::out);
	mine_file.open("mine_out", std::ios::out);
	std_file<<"TEST INT\n";

	 t_start_stl = clock();
	 stl_test_constructor_assignastion<int>(std_file);
	 stl_test_iterator<int>(std_file);
	 stl_test_modifier<int>(std_file);
	 stl_test_comparisons<int>(std_file);
	std_file<<"TEST STRUCT A\n";
	stl_test_constructor_assignastion<A>(std_file);
	 stl_test_iterator<A>(std_file);
	 stl_test_modifier<A>(std_file);
	 stl_test_comparisons<A>(std_file);

	 t_start_stl = clock() - t_start_stl;
	mine_file<<"TEST INT\n";

	 t_start_mine = clock();
	 test_constructor_assignastion<int>(mine_file);
	 test_iterator<int>(mine_file);
	 test_modifier<int>(mine_file);
	 test_comparisons<int>(mine_file);

	mine_file<<"TEST STRUCT A\n";
	test_constructor_assignastion<A>(mine_file);
	 test_iterator<A>(mine_file);
	 test_modifier<A>(mine_file);
	 test_comparisons<A>(mine_file);

	 t_start_mine = clock() - t_start_mine;
	std::cout<<"my timing = "<< ((float)t_start_mine) / CLOCKS_PER_SEC<<" timing stl ="<<((float)t_start_stl) / CLOCKS_PER_SEC<<" difference = "<<((float)t_start_mine) / CLOCKS_PER_SEC - ((float)t_start_stl) / CLOCKS_PER_SEC<<std::endl;
	 std_file.close();
	mine_file.close();
}
