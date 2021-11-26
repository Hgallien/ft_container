#ifndef STL_TEST_MAIN_HPP
#define STL_TEST_MAIN_HPP
#include <iostream>

#include <vector>
#include <fstream>
	template <typename T>
void	stl_test_constructor_assignastion(std::ofstream &out)
{
	std::cout<<"test111\n";
	out<<"////////////Test constructor/////////////////\n";
	std::vector<T> v_base(100,42);
	out<<"Size = "<<v_base.size()<<std::endl;
	v_base.reserve(1000);
	out<<"Capacity= "<<v_base.capacity()<<std::endl;
	out<<"Empty= "<<v_base.empty()<<std::endl;

	std::cout<<"test222\n";
	out<<"Test constructor n & val\n";
	for(typename  std::vector<T>::iterator it = v_base.begin();it!= v_base.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	std::vector<T> v_iterator(v_base.begin(),v_base.end());
	v_base.clear();

	out<<"Test constructor iterator\n";
	for(typename std::vector<T>::iterator it = v_base.begin();it!= v_base.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	std::vector<T> v_copy(v_iterator);
	for(typename std::vector<T>::iterator it = v_iterator.begin();it!= v_iterator.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	std::vector<T> v_ass = v_copy;

	out<<"Test constructor copy\n";
	for(typename std::vector<T>::iterator it = v_ass.begin();it!= v_ass.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";

	out<<"Test constructor vide base\n";
	std::vector<T> v_base_e;
	out<<"Size = "<<v_base.size()<<std::endl;
	out<<"Capacity= "<<v_base.capacity()<<std::endl;
	out<<"Empty= "<<v_base.empty()<<std::endl;

	std::cout<<"test333\n";
	for(typename std::vector<T>::iterator it = v_base_e.begin();it!= v_base_e.end(); it++)
	{
		out<<*it<<" ";
	}

	std::cout<<"test444\n";
	out<<"\n";

	// out<<"Test constructor vide iterator range\n";
//
	// std::cout<<"test44444444444\n";
	// std::vector<T> v_iterator_e(v_base_e.begin(),v_base.end());
//
	// std::cout<<"test888888888888888\n";
	// v_base_e.clear();
//
	// std::cout<<"test555\n";
	// for(typename std::vector<T>::iterator it = v_iterator_e.begin();it!= v_iterator_e.end(); it++)
	// {
		// out<<*it<<" ";
//
	// }
	// out<<"\n";
//
	// out<<"Test constructor vide copy\n";
	// std::vector<T> v_copy_e(v_iterator_e);
	// for(typename std::vector<T>::iterator it = v_iterator_e.begin();it!= v_iterator_e.end(); it++)
	// {
		// out<<*it<<" ";
	// }
	// out<<"\n";
//
	// std::vector<T> v_ass_e = v_copy_e;
	// for(typename std::vector<T>::iterator it = v_ass_e.begin();it!= v_ass_e.end(); it++)
	// {
		// out<<*it<<" ";
	// }
	// out<<"\n";


}

	template <typename T>
void	stl_test_iterator(std::ofstream &out)
{
	std::vector<T> v;
	for (int i = 0 ; i<100; i++)
	{
			v.push_back(i);
	}

	typename std::vector<T>::iterator it = v.begin();
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
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;

  out << "Mutable reverse iterator" << std::endl;
  for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;

  std::vector<int> const cIntVect(v);
  out << "Const iterator" << std::endl;
  for (std::vector<int>::const_iterator it = cIntVect.begin(); it != cIntVect.end(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;

  out << "Reverse const iterator" << std::endl;
  for (std::vector<int>::const_reverse_iterator it = cIntVect.rbegin(); it != cIntVect.rend(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;
}

void stl_all_comparisons(std::vector<int> const & a, std::vector<int> const & b,std::ofstream &out) {
  std::boolalpha(out);
  out << "a == b : " << (a == b) << std::endl;
  out << "a != b : " << (a != b) << std::endl;
  out << "a < b : " << (a < b) << std::endl;
  out << "a > b : " << (a > b) << std::endl;
  out << "a >= b : " << (a >= b) << std::endl;
  out << "a <= b : " << (a <= b) << std::endl;
}

template<typename T>
void	stl_print_vect(std::vector<T> v,std::ofstream &out)
{
	for(typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		out<<*it<<" ";
	}
		out<<"\n";
}
void stl_test_comparisons(std::ofstream &out) {
  
	std::vector<int> v1;

	std::vector<int> v1_b;

	std::vector<int> v2;
	std::vector<int> v2_b;
	std::vector<int> v3;
	std::vector<int> v3_b;
	for (int i = 0 ; i < 4 ; i++)
	{	
		v1.push_back(i);
		v1_b.push_back(i);
	}
  	for (int i = 0 ; i < 5 ; i++)
	{	
		v2.push_back(i);
	}
for (int i = 0 ; i < 3 ; i++)
	{	
		v2_b.push_back(i);
	}
		v3.push_back(0);
		v3.push_back(1);
		v3.push_back(10);
  		v3.push_back(0);
		v3.push_back(1);
		v3.push_back(1);
  stl_all_comparisons(v1, v1_b,out);
  stl_all_comparisons(v1, v2,out);
  stl_all_comparisons(v1, v2_b,out);
 stl_all_comparisons(v1, v3,out);
  stl_all_comparisons(v1, v3_b,out);
}

template <typename T>
void	stl_test_modifier(std::ofstream &out)
{
	out<<"/////////////////Test modifiers  & access////////////////\n";
	std::vector<T> v_b;

		out<<"Test push_back \n";
	for (int i = 0 ; i < 1000 ; i ++)
	{
		v_b.push_back(i);
	}
	for(typename  std::vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";

	out<<"Test insert  simple \n";
	v_b.insert(v_b.begin() + 3, -100);
	
	out<<"Test insert  simple +n \n";
	v_b.insert(v_b.begin() + 40, 10,42);

	out<<"Test insert  simple range \n";
	std::vector<T> v_b2(33,10);
	v_b.insert(v_b.begin() + 100, v_b2.begin(),v_b2.end());
	for(typename  std::vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";

	out<<"Test pop_back \n";
	for (int i = 0 ; i < 100 ; i ++)
	{
		v_b.pop_back();
	}
	for(typename  std::vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";

	out<<"Test erase one\n";
	v_b.erase(v_b.begin());
	for(typename  std::vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";

	out<<"Test erase one4\n";
	v_b.erase(v_b.begin(), v_b.end() - 10);

	out<<"Test erase range\n";
	for(typename  std::vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}

	out<<"\n";

	out<<"Test operator[] \n";
	for (unsigned int i = 0 ; i <v_b.size();i++)
	{
		out<<v_b[i]<<" ";
	}
	out<<"\n";
	
	out<<"Test swap \n";
	std::vector<T> swapy(4,4);
	v_b.swap(swapy);
	for(typename  std::vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	for(typename  std::vector<T>::iterator it = swapy.begin();it!= swapy.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	
	out<<"Test swap vide\n";
	v_b.swap(swapy);
	std::vector<T> vide;
	v_b.swap(vide);
	for(typename  std::vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		out<<*it<<" ";
	}
	out<<"\n";
	
	for(typename  std::vector<T>::iterator it = vide.begin();it!= vide.end(); it++)
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
#endif 
