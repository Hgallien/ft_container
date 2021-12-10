
#ifndef TEST_MAIN_HPP
#define TEST_MAIN_HPP
#include <iostream>
#include "map.hpp"
#include <fstream>
template<typename K,typename C>
void print_map_ez(map<K,C> &m)
{
	int i = 0;
	for( typename map<K,C>::iterator it = m.begin(); it!= m.end(); it++)
	{
		std::cout <<"("<<it->first<<") "<<"("<<it->second<<")\n";
		i++;
		if (i >30)
			return;
	}
	std::cout<<"\n";
}

template <typename K,typename C>
void	test_iterator(std::ofstream &out)
{
	map<K,C> m;
	for (int i = 0 ; i<100; i++)
	{
			m.insert(pair<K,C>(K(i),C(i)));
	}

	typename map<K,C>::iterator it = m.begin();

	typename map<K,C>::iterator it2 = m.begin();
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
  for (typename map<K,C>::iterator it = m.begin(); it != m.end(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;

  out << "Mutable reverse iterator" << std::endl;
  for (typename map<K,C>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;

  map<K,C> const cIntVect(m);
  out << "Const iterator" << std::endl;
  for (typename map<K,C>::const_iterator it = cIntVect.begin(); it != cIntVect.end(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;

  out << "Reverse const iterator" << std::endl;
  for (typename map<K,C>::const_reverse_iterator it = cIntVect.rbegin(); it != cIntVect.rend(); ++it)
    out << *it << ", ";
  out << "END" << std::endl;
}
template<typename K,typename C>
void print_map_ez(map<K,C> &m, std::ofstream& out)
{
	for( typename map<K,C>::iterator it = m.begin(); it!= m.end(); it++)
	{
		out <<"("<<it->first<<") "<<"("<<it->second<<")\n";
	}
	out<<"\n";
}
template<typename  K  ,typename C>
void	test_constructor_assignastion(std::ofstream &out)
{
	
	out<<"/////TEST ALL INSERT//// "<<std::endl;
	map<K,C> m;
	map<K,C> m2;
	out<<"Size = "<<m.size()<<std::endl;
	out<<"Empty= "<<m.empty()<<std::endl;
	out<<"test insert base &operator [] "<<std::endl;
	for (int i = 0 ; i < 250; i++)
	{
		m.insert(pair<K,C>(K(i),C(i)));
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
		m2.insert(m2.begin(),pair<K,C>(K(i),C(i)));
	}
	out<<"Size = "<<m2.size()<<std::endl;

	out<<"Empty= "<<m2.empty()<<std::endl;

	print_map_ez<K,C>(m2,out);
	out<<"test insert range "<<std::endl;
	m.insert(m2.begin(),m2.end());
	//

	out<<"Size = "<<m.size()<<std::endl;
	out<<"Empty= "<<m.empty()<<std::endl;
//
// //
//
	print_map_ez<K,C>(m,out);
	// //
	out<<"/////TEST CONSTRUCTOR//// "<<std::endl;

	out<<"test cpy  "<<std::endl;
	map<K,C> m_cpy(m);
	m.clear();
	print_map_ez<K,C>(m_cpy,out);
	out<<"Size = "<<m_cpy.size()<<std::endl;
	out<<"Empty= "<<m_cpy.empty()<<std::endl;

	out<<"test range  "<<std::endl;
//
	map<K,C> m_range(m_cpy.begin(),m_cpy.end());
	print_map_ez<K,C>(m_range,out);
	m_cpy.clear();
//
	out<<"test assignation"<<std::endl;
	map<K,C> m_ass;
	m_ass = m_range;
	m_range.clear();
	print_map_ez<K,C>(m_ass,out);
}
template <typename K,typename C>
void	test_erase_find_bound(std::ofstream &out)
 {
	map<K,C> m;
	for(int i = 0; i<10;i++)
	{
		m.insert(pair<K,C>(K(i),C(i)));
	}
	out<<"////TEST MODIFIERS////\n";
	out<<"test erase iterator\n";
	for(int i = 0 ; i < 5; i ++)
	{

		m.erase(m.begin());

	}
	print_map_ez<K,C>(m,out);

//
	out<<"test erase key\n";

	map<K,C> m2;
	for(int i = 0; i<200;i++)
	{

		m2.insert(pair<K,C>(K(i),C(i)));
	}

	for(int i = 12 ; i < 25; i ++)
	{
		m2.erase(K(i));

	// print_map_ez<K,C>(m2);
	}
	// m2.print_tree();
	out<<"size after erase key = "<<m2.size()<<std::endl;

	print_map_ez<K,C>(m2,out);

	typename map<K,C>::iterator it_e = m2.end();
	for (int i = 0 ; i < 10 ; i++)
		it_e--;
//
	out<<"test erase range\n";
	m2.erase(it_e,m2.end());

	print_map_ez<K,C>(m2,out);
	out<<"test find \n";

	typename map<K,C>::iterator it;
	for(int i = 0 ; i < 400; i ++)
	{
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
	out<<"test count\n";
		for(int i = 0 ; i < 189; i ++)
	{

			 out<<"count de "<<i<<"="<<((m2.count(K(i))))<<std::endl;
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
