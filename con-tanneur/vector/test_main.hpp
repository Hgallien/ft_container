
#ifndef TEST_MAIN_HPP
#define TEST_MAIN_HPP
#include "vector.hpp"

#include <fstream>

#include <iostream>
using namespace ft;
	template <typename T>
void	test_constructor_assignastion(std::ofstream &out)
{

	out<<"////////////Test constructor/////////////////\n";
	vector<T> v_base(100,T(42));
	out<<"Size = "<<v_base.size()<<std::endl;
	v_base.reserve(1000);
	out<<"Capacity= "<<v_base.capacity()<<std::endl;
	out<<"Empty= "<<v_base.empty()<<std::endl;

	out<<"Test constructor n & val\n";
	for(typename  vector<T>::iterator it = v_base.begin();it!= v_base.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	vector<T> v_iterator(v_base.begin(),v_base.end());
	v_base.clear();

	out<<"Test constructor iterator\n";
	for(typename vector<T>::iterator it = v_base.begin();it!= v_base.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	vector<T> v_copy(v_iterator);
	for(typename vector<T>::iterator it = v_iterator.begin();it!= v_iterator.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	vector<T> v_ass = v_copy;

	out<<"Test constructor copy\n";
	for(typename vector<T>::iterator it = v_ass.begin();it!= v_ass.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	//
	out<<"Test constructor vide base\n";
	vector<T> v_base_e;
	out<<"Size = "<<v_base.size()<<std::endl;
	out<<"Capacity= "<<v_base_e.capacity()<<std::endl;
	out<<"Empty= "<<v_base.empty()<<std::endl;
	for(typename vector<T>::iterator it = v_base_e.begin();it!= v_base_e.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
}

	template <typename T>
void	test_iterator(std::ofstream &out)
{
	vector<T> v;
	for (int i = 0 ; i<100; i++)
	{
		v.push_back(i);
	}

	typename vector<T>::iterator it = v.begin();
	out << "*it = " << *it << std::endl;
	// operator++
	out << "++it = " << *(++it) << ", now *it = " << *it << std::endl;
	// operator++(int)
	out << "it++ = " << *(it++) << ", now *it = " << *it << std::endl;
	// operator--
	out << "--it = " << *(--it) << ", now *it = " << *it << std::endl;
	// operator--
	out << "it-- = " << *(it--) << ", now *it = " << *it << std::endl;
	// operator[]
	out << "it[0] = " << it[0] << ", it[2] = " << it[2] << std::endl;
	// operator+=
	out << "it += 2, now *it = " << *(it += 2) << std::endl;
	// operator-=
	out << "it -= 1, now *it = " << *(it -= 1) << std::endl;
	// operator-
	out << "*(it - 1) = " << *(it - 1) << std::endl;
	// operator+
	out << "*(it + 1) = " << *(it + 1) << std::endl;
	// operator+
	out << "*(1 + it) = " << *(1 + it) << std::endl;
	// operator-
	out << "*(it - (it + 2)) = " << (it - (it + 2)) << std::endl;
	out << "*(it - (it - 1)) = " << (it - (it - 1)) << std::endl;
	// operator==
	out << "it == it : " << (it == it) << std::endl;
	out << "it == (it + 1) : " << (it == (it + 1)) << std::endl;
	// operator!=
	out << "it != (it + 1) : " << (it != (it + 1)) << std::endl;
	out << "it != it : " << (it != it) << std::endl;
	// operator<
	out << "it < it : " << (it < it) << std::endl;
	out << "it < (it + 1) : " << (it < (it + 1)) << std::endl;
	// operator>
	out << "it > it : " << (it > it) << std::endl;
	out << "it > (it - 1) : " << (it > (it - 1)) << std::endl;
	// operator<=
	out << "it <= it : " << (it <= it) << std::endl;
	out << "it <= (it + 1) : " << (it <= (it + 1)) << std::endl;
	// operator>=
	out << "it >= it : " << (it >= it) << std::endl;
	out << "it >= (it - 1) : " << (it >= (it - 1)) << std::endl;
	out << "(it + 3) - it = " << (it + 3) - it << std::endl;


	out << "Mutable iterator" << std::endl;
	for (typename vector<T>::iterator it = v.begin(); it != v.end(); ++it)
		out << *it << ", ";
	out << "END" << std::endl;

	out << "Mutable reverse iterator" << std::endl;
	for (typename vector<T>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
		out << *it << ", ";
	out << "END" << std::endl;

	vector<T> const cIntVect(v);
	out << "Const iterator" << std::endl;
	for (typename vector<T>::const_iterator it = cIntVect.begin(); it != cIntVect.end(); ++it)
		out << *it << ", ";
	out << "END" << std::endl;

	out << "Reverse const iterator" << std::endl;
	for (typename vector<T>::const_reverse_iterator it = cIntVect.rbegin(); it != cIntVect.rend(); ++it)
		out << *it << ", ";
	out << "END" << std::endl;
}
template<typename T>
void all_comparisons(vector<T> const & a, vector<T> const & b,std::ofstream &out) {
	std::boolalpha(out);
	out << "a == b : " << (a == b) << std::endl;
	out << "a != b : " << (a != b) << std::endl;
	out << "a < b : " << (a < b) << std::endl;
	out << "a > b : " << (a > b) << std::endl;
	out << "a >= b : " << (a >= b) << std::endl;
	out << "a <= b : " << (a <= b) << std::endl;
}

	template<typename T>
void	print_vect(vector<T> v,std::ofstream &out)
{
	for(typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
}
template<typename T>
void test_comparisons(std::ofstream &out) {

	vector<T> v1;

	vector<T> v1_b;

	vector<T> v2;
	vector<T> v2_b;
	vector<T> v3;
	vector<T> v3_b;
	for (int i = 0 ; i < 4 ; i++)
	{	
		v1.push_back(T(i));
		v1_b.push_back(T(i));
	}
	for (int i = 0 ; i < 5 ; i++)
	{	
		v2.push_back(T(i));
	}
	for (int i = 0 ; i < 3 ; i++)
	{	
		v2_b.push_back(i);
	}
	v3.push_back(T(0));
	v3.push_back(T(1));
	v3.push_back(T(10));
	v3.push_back(T(0));
	v3.push_back(T(1));
	v3.push_back(T(1));
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
	vector<T> v_b;

	out<<"Test push_back \n";
	for (int i = 0 ; i < 1000 ; i ++)
	{
		v_b.push_back(T(i));
	}
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";

	out<<"Test insert  simple \n";
	v_b.insert(v_b.begin() + 3, T(-100));
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"Test insert  simple +n \n";
	v_b.insert(v_b.begin() + 40, 10,T(42));
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"Test insert  simple range\n";
	vector<T> v_b2(33,T(10));
	// typename  vector<T>::iterator it_test = v_b.begin() + 100;
	// out<<"size = "<<v_b.size()<<"position  = "<< *it_test<<::std::endl;
	v_b.insert(v_b.begin() + 100, v_b2.begin(),v_b2.end());
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";

	out<<"Test pop_back \n";
	for (int i = 0 ; i < 100 ; i ++)
	{
		v_b.pop_back();
	}
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	//
	out<<"Test erase one\n";
	v_b.erase(v_b.begin());
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";

	out<<"Test erase one4\n";
	v_b.erase(v_b.begin(), v_b.end() - 10);

	out<<"Test erase range\n";
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	//
	out<<"\n";

	out<<"Test operator[] \n";
	for (unsigned int i = 0 ; i <v_b.size();i++)
	{
		out<<v_b[i]<<" ";
	}
	out<<"\n";

	out<<"Test swap \n";
	vector<T> swapy(4,T(4));
	v_b.swap(swapy);
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	for(typename  vector<T>::iterator it = swapy.begin();it!= swapy.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";

	out<<"Test swap vide\n";
	v_b.swap(swapy);
	vector<T> vide;
	v_b.swap(vide);
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";

	for(typename  vector<T>::iterator it = vide.begin();it!= vide.end(); it++)
	{
		out<<*it<<" ";
	}
	v_b.swap(vide);

	out<<"Test front\n";
	out<<v_b.front()<<std::endl;

	out<<"Test AT\n";
	try{
		out<<v_b.at(100);
	}
	catch (std::exception & e)
	{
		out<<e.what()<<std::endl;
	}
	try{
		out<<v_b.at(1)<<std::endl;
	}
	catch (std::exception & e)
	{
		out<<e.what()<<std::endl;
	}
	out<<"Test AT\n";
	out<<v_b.back()<<std::endl;
}
template<typename T>
void test_it_validity(std::ofstream &out) {
	vector<T> vect1;
	vector<T> vect2;
		for (int i = 0; i < 10; i++) {
		vect1.push_back(i);
	}
	for (int i = 10; i < 20; i++) {
		vect2.push_back(i);
	}
	typename vector<T>::iterator it1 = vect1.begin() + 3;
	typename vector<T>::const_iterator itC = vect1.begin();

	typename vector<T>::iterator it2 = vect2.begin() + 3;
	
	out << "(it1 == itC) =" << (it1 == itC) << std::endl;
	out << "(it1 != itC) =" << (it1 != itC) << std::endl;
	int* p1 = &vect1[4];
	int* p2 = &vect2[4];
	int& r1 = vect1[5];
	int& r2 = vect2[5];
	print_vect(vect1,out);
	print_vect(vect2 ,out);
	swap(vect1, vect2);
	print_vect(vect1,out);
	print_vect(vect2 ,out);
	out << *it1 << std::endl;
	out << *it2 << std::endl;
	out << *p1 << std::endl;
	out << *p2 << std::endl;
	out << r1 << std::endl;
	out << r2 << std::endl;
	*it1 = -1;
	*it2 = -2;
	*p1 = -3;
	*p2 = -4;
	r1 = -5;
	r2 = -6;
	print_vect(vect1, out);
	print_vect(vect2 ,out);
}
#endif
