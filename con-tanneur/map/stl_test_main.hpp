
#ifndef STL_TEST_MAIN_HPP
#define STL_TEST_MAIN_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <utility>
#include "utils.hpp"

	template <class Key, class T>
std::ostream& operator<<(std::ostream& out, const std::pair<Key,T> &w)
{
	out <<"("<<w.first<<") "<<"("<<w.second<<")\n";
	return out;
}
	template <typename K,typename C>
void	stl_test_iterator(std::ofstream &out)
{
	std::map<K,C> m;
	for (int i = 0 ; i<100; i++)
	{
			m.insert(std::pair<K,C>(K(i),C(i)));
	}

	typename std::map<K,C>::iterator it = m.begin();

	typename std::map<K,C>::iterator it2 = m.begin();
	it2++;
	out << "*it = " << *it << std::endl;
  // operator++
  out << "++it = " << *(++it) << ", now *it = " << *it << std::endl;
  // operator++(int)
  out << "it++ = " << *(it++) << ", now *it = " << *it << std::endl;
  // operator--
  out << "--it = " << *(--it) << ", now *it = " << *it << std::endl;
  // operator--
  out << "it-- = " << *(it--) << ", now *it = " << *it << std::endl;
// operator==
  out << "it == it : " << (it == it) << std::endl;
  out << "it == (it + 1) : " << (it == (it2)) << std::endl;
  // operator!=
  out << "it != (it + 1) : " << (it != (it2 )) << std::endl;
  out << "it != it : " << (it != it) << std::endl;

  out << "Mutable iterator" << std::endl;
  for (typename std::map<K,C>::iterator it = m.begin(); it != m.end(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;

  out << "Mutable reverse iterator" << std::endl;
  for (typename std::map<K,C>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;

  std::map<K,C> const cIntVect(m);
  out << "Const iterator" << std::endl;
  for (typename std::map<K,C>::const_iterator it = cIntVect.begin(); it != cIntVect.end(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;

  out << "Reverse const iterator" << std::endl;
  for (typename std::map<K,C>::const_reverse_iterator it = cIntVect.rbegin(); it != cIntVect.rend(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;
}
// namespace std
// {
template<typename K,typename C>
void print_map_ez(std::map<K,C> &m, std::ofstream& out)
{
	for( typename std::map<K,C>::iterator it = m.begin(); it!= m.end(); it++)
	{
		out <<"("<<it->first<<") "<<"("<<it->second<<")\n";
	}
	out<<"\n";
}

template<typename  K  ,typename C>
void	stl_test_constructor_assignastion(std::ofstream &out)
{
	
	out<<"/////TEST ALL INSERT//// "<<std::endl;
	std::map<K,C> m;
	std::map<K,C> m2;
	out<<"Size = "<<m.size()<<std::endl;
	out<<"Empty= "<<m.empty()<<std::endl;
	out<<"test insert base &operator [] "<<std::endl;
	for (int i = 0 ; i < 250; i++)
	{
		m.insert(std::pair<K,C>(K(i),C(i)));
	}
	for (int i = 250 ; i <500; i++)
	{
		m[K(i)] = C(i) ;
	}

	out<<"Size = "<<m.size()<<std::endl;
	out<<"Empty= "<<m.empty()<<std::endl;
	print_map_ez<K,C>(m,out);
	out<<"test insert hint "<<std::endl;
	for (int i = 500 ; i < 800; i++)
	{
		m2.insert(m2.begin(),std::pair<K,C>(K(i),C(i)));
	}
	out<<"Size = "<<m2.size()<<std::endl;

	out<<"Empty= "<<m2.empty()<<std::endl;

	print_map_ez<K,C>(m2,out);
	out<<"test insert range "<<std::endl;
	m.insert(m2.begin(),m2.end());
	//

	out<<"Size = "<<m.size()<<std::endl;
	out<<"Empty= "<<m.empty()<<std::endl;

	// std::cout<<"end= "<<*(m.end())<<std::endl;
//
	// std::cout<<"begin= "<<*(m.begin())<<std::endl;
//
	// std::cout<<"Size = "<<m.size()<<std::endl;
	print_map_ez<K,C>(m,out);
	// //
	out<<"/////TEST CONSTRUCTOR//// "<<std::endl;

	out<<"test cpy  "<<std::endl;
	std::map<K,C> m_cpy(m);
	m.clear();
	print_map_ez<K,C>(m_cpy,out);
	out<<"Size = "<<m_cpy.size()<<std::endl;
	out<<"Empty= "<<m_cpy.empty()<<std::endl;

	out<<"test range  "<<std::endl;

	std::cout<<"test range  "<<std::endl;
	std::map<K,C> m_range(m_cpy.begin(),m_cpy.end());
	print_map_ez<K,C>(m_range,out);
	m_cpy.clear();

	out<<"test assignation"<<std::endl;
	std::map<K,C> m_ass;
	m_ass = m_range;
	m_range.clear();
	print_map_ez<K,C>(m_ass,out);
}
template <typename K,typename C>
void	stl_test_erase_find_bound(std::ofstream &out)
 {
	std::map<K,C> m;
	for(int i = 0; i<10;i++)
	{

		m.insert(std::pair<K,C>(K(i),C(i)));
		// m.print_tree();
		// std::cout<<"dans insert right left = "<<(m.getHead())->getSright()<<" "<<(m.getHead())->getSleft()<<std::endl;
	}


	out<<"////TEST MODIFIERS////\n";
	out<<"test erase iterator\n";
	// m.print_tree();
	for(int i = 0 ; i < 5; i ++)
	{

		// std::cout<<"dans erase for right left = "<<(m.getHead())->getSright()<<" "<<(m.getHead())->getSleft()<<std::endl;
		// std::cout<<"erase iterator i  "<<i<<std::endl;
		m.erase(m.begin());

	// m.print_tree();
	}
	print_map_ez<K,C>(m,out);

//
	out<<"test erase key\n";

	std::cout<<"test erase key\n";
	std::map<K,C> m2;
	for(int i = 0; i<200;i++)
	{

		m2.insert(std::pair<K,C>(K(i),C(i)));
	}
	for(int i = 12 ; i < 25; i ++)
	{

	// print_map_ez<K,C>(m2);
		// std::cout<<"erase key i ="<<i<<std::endl;
		m2.erase(K(i));
	}

	out<<"size after erase key = "<<m2.size()<<std::endl;
	print_map_ez<K,C>(m2,out);
//

	typename std::map<K,C>::iterator it_e = m2.end();
	for (int i = 0 ; i < 10 ; i++)
		it_e--;
//
	std::cout<<"test erase range\n";
	out<<"test erase range\n";
	m2.erase(it_e,m2.end());

	print_map_ez<K,C>(m2,out);
	std::cout<<"test erase range3\n";
	out<<"test find \n";

	std::cout<<"test find \n";
	typename std::map<K,C>::iterator it;
	for(int i = 0 ; i < 400; i ++)
	{
		std::cout<<" i = "<<i<<"\n";
		it = m2.find(K(i));
		if (it != m2.end())
		{
			out<<" it "<<*it<<"\n";
		}
		else
		{
			out<<" not found "<<"\n";
		 }
	}
		std::cout<<" size = "<<m2.size()<<"\n";
	out<<"test count\n";
		for(int i = 0 ; i < 189; i ++)
	{

		std::cout<<"  la  i = "<<i<<std::endl;
			 out<<"count de "<<i<<"="<<((m2.count(K(i))))<<std::endl;

		std::cout<<"  la  2i = "<<i<<std::endl;
			out<<"equal range de "<<i<<"="<<(*((m2.equal_range(K(i))).first))<<std::endl;
			out<<"equal range de "<<i<<"="<<(*((m2.equal_range(K(i))).first))<<std::endl;
			m2.equal_range(K(i));
	 }

			out<<"1 lower bound de "<<100<<"="<<(*(m2.lower_bound(K(100))))<<std::endl;
			out<<"2 lower bound de "<<100<<"="<<(*(m2.lower_bound(K(100))))<<std::endl;
			// out<<"3 lower bound de "<<500<<"="<<(*(m2.lower_bound(K(500))))<<std::endl;
			// out<<"4 upper bound de "<<500<<"="<<(*(m2.upper_bound(K(500))))<<std::endl;
			// out<<"5 upper bound de "<<250<<"="<<(*(m2.upper_bound(K(250))))<<std::endl;
			// out<<"6 upper bound de "<<250<<"="<<(*(m2.upper_bound(K(250))))<<std::endl;

}

#endif 
