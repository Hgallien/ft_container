#include "map.hpp"
#include <iostream>
#include <fstream>
#include "test_main.hpp"
#include "stl_test_main.hpp"

#include "Iterator.hpp"

#include <cstdlib>

template <class Container>
void print_container(Container const & m,std::ofstream &out) {
	for (typename Container::const_iterator it = m.begin(); it != m.end(); ++it) {
		if (it != m.begin())
			out << ", ";
		out << *it;

	}
}
template <class Container>
void print_container_nl(Container const & m,std::ofstream &out) {
	print_container(m,out);
	out << std::endl;
}

template <class Iterator>
void print_all(Iterator first, Iterator last,std::ofstream &out) {
	for (Iterator it = first; it != last; ++it) {
		if (it != first)
			out << ", ";
		out << *it;
		out<<"for print all"<< *last<<"\n";
	}
	out<<"end print all\n";
}
template <class Iterator>
void print_all_nl(Iterator first, Iterator last,std::ofstream &out) {
	print_all(first, last);
	out << std::endl;
}
void stl_test_only_one_key(std::ofstream &out) {
	std::map<std::string, std::string> m;

	m["chat"] = "chien";
	m["chat"] = "cheval";
	m["chat"] = "ça va ?";
	out << "Map is of size " << m.size() << ": ";
	print_container_nl(m,out);
}

void stl_test_container_ordered(std::ofstream &out) {
	std::map<int, int> m;

	m[3] = 3;
	m[0] = 0;
	m[4] = 4;
	m[2] = 2;
	m[1] = 1;
	out << "Should be ordered : ";
	print_container_nl(m,out);
}

void stl_test_iterator_valid(std::ofstream &out) {
	std::map<int, int> m;

	for (int i = 0; i < 5; ++i) {
		m[i] = i;
	}
	std::map<int, int>::iterator it = m.begin();
	++it; ++it;
	out << "Map is : ";
	print_container_nl(m,out);
	out << "Iterator is ponting at " << *it << std::endl;
	out << "Erasing keys 1 and 3" << std::endl;
	m.erase(1); m.erase(3);
	out << "Iterator is ponting at " << *it << std::endl;
	out << "it++;" << std::endl; it++;
	out << "Iterator is ponting at " << *it << std::endl;
	out << "it--; it--;" << std::endl; it--; it--;
	out << "Iterator is ponting at " << *it << std::endl;
}

void stl_test_swap_move_only_pointers(std::ofstream &out) {
	std:: map<int, int> m1;
	std::map<int, int> m2;
	std::pair<const int, int> *addr1;
	std::pair<const int, int> *addr2;

	m1[0] = 0;
	out << "Before swap:" << std::endl;
	out << "m1 = "; print_container(m1,out); out << " and m2 = "; print_container_nl(m2,out);
	// out << "Address of " << *m1.begin() << " : " << &*m1.begin() << std::endl;
	addr1 = &*m1.begin();
	m1.swap(m2);
	out << "After swap:" << std::endl;
	out << "m1 = "; print_container(m1,out); out << "and m2 = "; print_container_nl(m2,out);
	// out << "Address of " << *m2.begin() << " : " << &*m2.begin() << std::endl;
	addr2 = &*m2.begin();
	out << "Address before and after are equal ? " << (addr1 == addr2) << std::endl;
}

void test_only_one_key(std::ofstream &out) {
	map<std::string, std::string> m;

	m["chat"] = "chien";
	m["chat"] = "cheval";
	m["chat"] = "ça va ?";
	out << "Map is of size " << m.size() << ": ";
	print_container_nl(m,out);
}

void test_container_ordered(std::ofstream &out) {
	map<int, int> m;

	m[3] = 3;
	m[0] = 0;
	m[4] = 4;
	m[2] = 2;
	m[1] = 1;
	out << "Should be ordered : ";
	print_container_nl(m,out);
}

void test_iterator_valid(std::ofstream &out) {
	map<int, int> m;

	for (int i = 0; i < 5; ++i) {
		m[i] = i;
	}
	map<int, int>::iterator it = m.begin();
	++it; ++it;
	out << "Map is : ";
	print_container_nl(m,out);
	out << "Iterator is ponting at " << *it << std::endl;
	out << "Erasing keys 1 and 3" << std::endl;
	m.erase(1); m.erase(3);
	out << "Iterator is ponting at " << *it << std::endl;
	out << "it++;" << std::endl; it++;
	out << "Iterator is ponting at " << *it << std::endl;
	out << "it--; it--;" << std::endl; it--; it--;
	out << "Iterator is ponting at " << *it << std::endl;
}

void test_swap_move_only_pointers(std::ofstream &out) {
	map<int, int> m1;
	map<int, int> m2;
	pair<const int, int> *addr1;
	pair<const int, int> *addr2;

	m1[0] = 0;
	out << "Before swap:" << std::endl;
	out << "m1 = "; print_container(m1,out); out << " and m2 = "; print_container_nl(m2,out);
	// out << "Address of " << *m1.begin() << " : " << &*m1.begin() << std::endl;
	addr1 = &*m1.begin();
	m1.swap(m2);
	out << "After swap:" << std::endl;
	out << "m1 = "; print_container(m1,out); out << "and m2 = "; print_container_nl(m2,out);
	// out << "Address of " << *m2.begin() << " : " << &*m2.begin() << std::endl;
	addr2 = &*m2.begin();
	out << "Address before and after are equal ? " << (addr1 == addr2) << std::endl;
}
void	test_swap_itVal_ordered(std::ofstream &out_mine,std::ofstream &out_std)
{
	stl_test_only_one_key(out_std) ;

	stl_test_container_ordered(out_std) ;


	stl_test_iterator_valid(out_std);


	stl_test_swap_move_only_pointers(out_std) ;

	test_only_one_key(out_mine) ;

	test_container_ordered(out_mine) ;


	test_iterator_valid(out_mine);


	test_swap_move_only_pointers(out_mine) ;

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

int main()
{
	std::ofstream std_file;
	std::ofstream mine_file;
	clock_t t_start_stl;
	clock_t t_start_mine;

	std_file.open("std_out", std::ios::out);
	mine_file.open("mine_out", std::ios::out);
	t_start_mine = clock();
	test_constructor_assignastion<const int,int>(mine_file);
	// test_erase_find_bound<const int,int>(mine_file);
	// test_iterator<const int,int>(mine_file);
	// test_constructor_assignastion<const int,A>(mine_file);
	// test_erase_find_bound<const int,A>(mine_file);
	// test_iterator<const int,A>(mine_file);
	t_start_mine = clock() - t_start_mine;
	t_start_stl = clock();
	stl_test_constructor_assignastion<const int,int>(std_file);
	// stl_test_erase_find_bound<const int,int>(std_file);
	// stl_test_iterator<const int,int>(std_file);
	// stl_test_constructor_assignastion<const int,A>(std_file);
	// stl_test_erase_find_bound<const int,A>(std_file);
	// stl_test_iterator<const int,A>(std_file);
	t_start_stl = clock() - t_start_stl;
	std::cout<<"my timing = "<< ((float)t_start_mine) / CLOCKS_PER_SEC<<" timing stl ="<<((float)t_start_stl) / CLOCKS_PER_SEC<<" difference = "<<((float)t_start_mine) / CLOCKS_PER_SEC - ((float)t_start_stl) / CLOCKS_PER_SEC<<std::endl;
	test_swap_itVal_ordered(mine_file,std_file);
	mine_file.close();
	std_file.close();
	
}
