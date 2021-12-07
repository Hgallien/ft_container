#include "map.hpp"
#include <iostream>
#include <fstream>
#include "test_main.hpp"
#include "stl_test_main.hpp"

#include <cstdlib>

template <class Container>
void print_container(Container const & m) {
  for (typename Container::const_iterator it = m.begin(); it != m.end(); ++it) {
    if (it != m.begin())
      std::cout << ", ";
    std::cout << *it;

  }
}
template <class Container>
void print_container_nl(Container const & m) {
  print_container(m);
  std::cout << std::endl;
}

template <class Iterator>
void print_all(Iterator first, Iterator last) {
  for (Iterator it = first; it != last; ++it) {
    if (it != first)
      std::cout << ", ";
    std::cout << *it;
  std::cout<<"for print all"<< *last<<"\n";
  }
  std::cout<<"end print all\n";
}
template <class Iterator>
void print_all_nl(Iterator first, Iterator last) {
  print_all(first, last);
  std::cout << std::endl;
}

template<typename T, size_t n>
size_t length(T (&)[n]) {
  return n;
}

template<typename T, size_t n>
T *array_end(T (&array)[n]) {
  return array + n;
}


template <class T1, class T2, class Comp>
void insert(map<T1, T2, Comp> & container, T1 k, T2 v) {
  pair<T1, T2> val = make_pair(k, v);
  std::cout << "Inserting " << val << std::endl;

  pair<typename map<T1, T2, Comp>::iterator, bool> ret = container.insert(val);

  std::cout << "Was present : " << ret.second << std::endl;
  std::cout << "Iterator points to " << *ret.first << std::endl;
}
void insert_many(map<int, int> & container, int n) {
  for (int i = 0; i < n; ++i) {
    container.insert(make_pair(i, i));
  }
}


void test_only_one_key() {
  map<std::string, std::string> m;

  m["chat"] = "chien";
  m["chat"] = "cheval";
  m["chat"] = "ça va ?";
  std::cout << "Map is of size " << m.size() << ": ";
  print_container_nl(m);
}

void test_container_ordered() {
  map<int, int> m;

  m[3] = 3;
  m[0] = 0;
  m[4] = 4;
  m[2] = 2;
  m[1] = 1;
  std::cout << "Should be ordered : ";
  print_container_nl(m);
}

void test_iterator_valid() {
  map<int, int> m;

  for (int i = 0; i < 5; ++i) {
    m[i] = i;
  }
  map<int, int>::iterator it = m.begin();
  ++it; ++it;
  std::cout << "Map is : ";
  print_container_nl(m);
  std::cout << "Iterator is ponting at " << *it << std::endl;
  std::cout << "Erasing keys 1 and 3" << std::endl;

  m.erase(1);

  print_container(m);
  std::cout << " between keys 1 and 3" << std::endl;
  // m.print_tree();
  m.erase(3);
  // m.print_tree();
  print_container(m);
	// for(it = m.begin(); it != m.end();it++)
	// {
	// if ((it.getAddr())->getTop() != 0)
	// std::cout<<*it<<"top = "<<((it.getAddr())->getTop())->getKey()<<std::endl;
	// else
		// std::cout<<*it<<std::endl;
	// }
	// m.print_tree();
  std::cout <<"end = "<< *m.end() << std::endl;
  print_container(m);
  std::cout << "Iterator is ponting at " << *it << std::endl;
  std::cout << "it++;" << std::endl; it++;
  std::cout << "Iterator is ponting at " << *it << std::endl;
  std::cout << "it--; it--;" << std::endl; it--; it--;
  std::cout << "Iterator is ponting at " << *it << std::endl;
}

// struct MyInt {
//   MyInt(): ia(new int) {}
//   MyInt(MyInt const & x): ia(new int) {}
//   ~MyInt() { delete ia; }
//   MyInt & operator=(MyInt const & x) {}
//   int *ia;
// }

void test_swap_move_only_pointers() {
  map<int, int> m1;
  map<int, int> m2;
  pair<const int, int> *addr1;
  pair<const int, int> *addr2;

  m1[0] = 0;
  std::cout << "Before swap:" << std::endl;
  std::cout << "m1 = "; print_container(m1); std::cout << " and m2 = "; print_container_nl(m2);
  // std::cout << "Address of " << *m1.begin() << " : " << &*m1.begin() << std::endl;
  addr1 = &*m1.begin();
  m1.swap(m2);
  std::cout << "After swap:" << std::endl;
  std::cout << "m1 = "; print_container(m1); std::cout << "and m2 = "; print_container_nl(m2);
  // std::cout << "Address of " << *m2.begin() << " : " << &*m2.begin() << std::endl;
  addr2 = &*m2.begin();
  std::cout << "Address before and after are equal ? " << (addr1 == addr2) << std::endl;
}

void test_last() {
  std::boolalpha(std::cout);
  test_only_one_key();
  std::cout << std::endl;
  test_container_ordered();
  std::cout << std::endl;
  test_iterator_valid();
  std::cout << std::endl;
  test_swap_move_only_pointers();
}

void test_insert()
{
  map<int, int> m0;

  std::boolalpha(std::cout);
  for (int i = 0; i < 5; ++i) {
    insert(m0, i, i);
  }
  for (int i = 0; i < 5; ++i) {
    insert(m0, i, 2 * i);
  }

  insert_many(m0, 10000);
}

void test_lower_bound() {

  std::cout <<" tlb 1 \n";
  map<int, int>  m10;
	for (int i = 0; i < 10; ++i) {
	m10[i] = i;
  }

  map<int,int>::iterator it;
  std::cout <<" tlb 1\n ";
  map<int, int> m = m10;
//
  std::cout <<" tlb 2 \n";
for(it = m.begin(); it != m.end();it++)
	{
	if ((it.getAddr())->getTop() != 0)
	std::cout<<*it<<"top = "<<((it.getAddr())->getTop())->getKey()<<std::endl;
	else
		std::cout<<*it<<std::endl;
	}

  // m.print_tree();
  m.erase(3);
//
  std::cout << "lower_bound of 2 in m : ";
	for(it = m.begin(); it != m.end();it++)
	{
	if ((it.getAddr())->getTop() != 0)
	std::cout<<*it<<"top = "<<((it.getAddr())->getTop())->getKey()<<std::endl;
	else
		std::cout<<*it<<std::endl;
	}
  std::cout <<" it = "<<*it<<" \n";
  it++;
   std::cout <<" it = "<<*it<<" \n";
  it++;
  std::cout <<" it = "<<*it<<" \n";
  it++;
  std::cout <<" it = "<<*it<<" \n";
  it++;
  // m.print_tree();
  print_all_nl(m.lower_bound(2), m.end());
  std::cout << "lower_bound of 3 in m : ";
  print_all_nl(m.lower_bound(3), m.end());
  std::cout << "lower_bound of 4 in m : ";
  print_all_nl(m.lower_bound(4), m.end());
}
void test_clear() {
  srand(time(NULL));
  map<int, int> m;

  for (int i = 0; i < 1000 ; ++i) {
    m[i] = rand();
    if (i > 0)
      std::cout << ", ";
  	std::cout<<"test clear i = "<<i<<std::endl;
  }

  	std::cout<<"test clear after while\n";
  m.clear();

  	std::cout<<"test clear after clear\n";
  print_container_nl(m);

  	std::cout<<"test clear after print\n";
  std::cout << m.size();

  	std::cout<<"test clear after size\n";
}

void test_swap() {
  map<int, int> m1, m2;

  for (int i = 0; i < 10; ++i) {
    m1[i] = i;
    m2[i] = 10 + i;
  }
  std::cout << "m1 = ";
  print_container_nl(m1);
  std::cout << "m2 = ";
  print_container_nl(m2);
  std::cout << "m1.swap(m2)..." << std::endl;
  m1.swap(m2);
  std::cout << "m1 = ";
  print_container_nl(m1);
  std::cout << "m2 = ";
  print_container_nl(m2);
  std::cout << "swap(m1, m2)..." << std::endl;
  swap(m1, m2);
  std::cout << "m1 = ";
  print_container_nl(m1);
  std::cout << "m2 = ";
  print_container_nl(m2);
}

void test_erase() {
  map<int, int> m;

  for (int i = 0; i < 10; ++i) {
    m[i] = i;
  }
  std::cout << "m.erase(2) = " << m.erase(2) << std::endl;
  print_container_nl(m);
  std::cout << "m.erase(2) = " << m.erase(2) << std::endl;
  print_container_nl(m);
  m.erase(m.begin());
  m.erase(--(m.end()));
  print_container_nl(m);
  map<int, int>::iterator it[2] = {m.begin(), m.end()};
  it[0]++; it[0]++;
  it[1]--; it[1]--;
  m.erase(it[0], it[1]);
  print_container_nl(m);
  std::cout << "size = " << m.size() << std::endl;
}

void test_iterator_types() {
  map<int, int> bst;

  for (int i = 0; i < 15; ++i)
    bst.insert(make_pair(i, i));

  std::cout << "Mutable iterator" << std::endl;
  for (map<int, int>::iterator it = bst.begin(); it != bst.end(); ++it)
	std::cout << *it << ", ";
  std::cout << "END" << std::endl;
	bst.print_tree();
  //
  std::cout << "Mutable reverse iterator" << std::endl;
  int i = 0;
  for(map<int,int>::iterator it2 = bst.begin(); it2 != bst.end();it2++)
	{
	if ((it2.getAddr())->getTop() != 0)
	std::cout<<*it2<<"top = "<<((it2.getAddr())->getTop())->getKey()<<std::endl;
	else
		std::cout<<*it2<<std::endl;
	}
  std::cout<<"ici\n";
  for (map<int, int>::reverse_iterator it = bst.rbegin(); it != bst.rend(); ++it)
  {
	  std::cout << *it << ", ";
  	i++;
	if (i == 20)
		break;
  }
  std::cout << "END" << std::endl;
//
  map<int, int> const cbst(bst);
  std::cout << "Const iterator" << std::endl;
  for (map<int, int>::const_iterator it = cbst.begin(); it != cbst.end(); ++it)
	std::cout << *it << ", ";
  std::cout << "END" << std::endl;

  std::cout << "Reverse const iterator" << std::endl;
  for (map<int, int>::const_reverse_iterator it = cbst.rbegin(); it != cbst.rend(); ++it)
	std::cout << *it << ", ";
  std::cout << "END" << std::endl;
}

// template <class Container>
// void print_container(Container const & m) {
	// for (typename Container::const_iterator it = m.begin(); it != m.end(); ++it) {
		// if (it != m.begin())
			// std::cout << ", ";
		// std::cout << *it;
	// }
// }
// template <class Container>
// void print_container_nl(Container const & m) {
	// print_0container(m);
	// std::cout << std::endl;
// }
void test_comparison_iters() {
  map<int, int> m;
  for (int i = 0; i < 10; i++)
    m[i] = i;
  map<int, int> const & cm = m;

  std::cout << "begin() == (const_iterator)begin() : " << (m.begin() == cm.begin()) << std::endl;
  std::cout << "(const_iterator)begin() == begin() : " << (cm.begin() == m.begin()) << std::endl;
  std::cout << "end() == (const_iterator)end() : " << (m.end() == cm.end()) << std::endl;
  std::cout << "(const_iterator)end() == end() : " << (cm.end() == m.end()) << std::endl;
  std::cout << "begin() == (const_iterator)end() : " << (m.begin() == cm.end()) << std::endl;
  std::cout << "(const_iterator)begin() == end() : " << (cm.begin() == m.end()) << std::endl;
  std::cout << "end() == (const_iterator)begin() : " << (m.end() == cm.begin()) << std::endl;
  std::cout << "(const_iterator)end() == begin() : " << (cm.end() == m.begin()) << std::endl;
}

void test() {
	map<int, int> m;


	for (int i = 0; i < 10; i++) {

	std::cout<<"ta race la 1\n";
		m[i] = i;
	}
	std::cout<<"end "<<*(m.end())<<std::endl;
	m.print_tree();

	// std::cout<<"ta race la 1.5\n";
	map<int, int> m_copy(m);

	std::cout<<"ta race la 2\n";
	print_container_nl(m_copy);

	map<int, int> m_assign;
	m_assign = m;
	print_container_nl(m_assign);
// //
	// // Make sure all was duplicated
	m.clear();
	std::cout<<"ta race la \n";
	print_container_nl(m_copy);
	print_container_nl(m_assign);

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
	
	std_file.open("std_out", std::ios::out);
	mine_file.open("mine_out", std::ios::out);
	test_constructor_assignastion<const int,int>(mine_file);
	test_erase_find_bound<const int,int>(mine_file);

	// stl_test_constructor_assignastion<const int,int>(std_file);
	// stl_test_erase_find_bound<const int,int>(std_file);
	// stl_test_constructor_assignastion<const int,int>(std_file);
	mine_file.close();
	std_file.close();
//
	// map< char, int> m;
//
	// // for (int i = 0 ; i <10 ; i+=2)
	// // {
		// // pair<const char,int> p1('a' + i,1 +i);
		// // m.insert(p1);
	// // }
	// // for (int i = 0 ; i <10 ; i+=2)
	// // {
		// // pair<const char,int> p1('b' + i,11 +i);
		// // m.insert(p1);
	// // }
// //
	// for (int i = 0 ; i <10 ; i++)
	// {
		// pair<const char,int> p1('a' + i,1 +i);
		// m.insert(p1);
		// std::cout<<"after insert \n";
	// }
	//
	 // // m.print_tree();
	// // m.print_tree();
	// // m.erase(m.begin());
	// // m.print_tree();
	// // m.erase(m.begin());
	// // m.print_tree();
	// // map<char,int>::iterator it = m.begin();
	// // m.erase(it);
	// // m.print_tree();
	// // std::cout<<"\\\\\\\\\\\\\\\\\\\\\\\n";
	// // it = m.begin()	;
	// // std::cout<<it->first<<std::endl;
	// // for(int x=0 ;x<1;x++)
	// // {
		// // it++;
		// // std::cout<<it->first<<std::endl;
	// // }
	// // std::cout<<"test main3\n";
	// // m.erase(it);
	// // std::cout<<"test main4\n";
	// // m.print_tree();
	// // std::cout<<"test main5\n";
	// map<char,int> mymap;
	// // std::cout<<"test main5.5\n";
	// // map<char,int>::iterator itlow,itup;
	// // std::cout<<"test main5.75\n";
	// //
	// map<char,int>::iterator it;
	// mymap['a']=20;
  // mymap.print_tree();
// for(it = mymap.begin(); it != mymap.end();it++)
	// {
	// if ((it.getAddr())->getTop() != 0)
	// std::cout<<*it<<"top = "<<((it.getAddr())->getTop())->getKey()<<std::endl;
	// else
		// std::cout<<*it<<std::endl;
	// }
//
	// std::cout<<"test main6\n";
	// mymap['b']=40;
  // mymap.print_tree();
	//
// for(it = mymap.begin(); it != mymap.end();it++)
	// {
	// if ((it.getAddr())->getTop() != 0)
	// std::cout<<*it<<"top = "<<((it.getAddr())->getTop())->getKey()<<std::endl;
	// else
		// std::cout<<*it<<std::endl;
	// }
//
  // std::cout<<"test main7\n";
	// mymap['c']=60;
  // mymap.print_tree();
//
// for(it = mymap.begin(); it != mymap.end();it++)
	// {
	// if ((it.getAddr())->getTop() != 0)
	// std::cout<<*it<<"top = "<<((it.getAddr())->getTop())->getKey()<<std::endl;
	// else
		// std::cout<<*it<<std::endl;
	// }
//
	// std::cout<<"test main8\n";
	// mymap['d']=80;
  // mymap.print_tree();
//
// for(it = mymap.begin(); it != mymap.end();it++)
	// {
	// if ((it.getAddr())->getTop() != 0)
	// std::cout<<*it<<"top = "<<((it.getAddr())->getTop())->getKey()<<std::endl;
	// else
		// std::cout<<*it<<std::endl;
	// }
	// std::cout<<"test main9\n";
	// mymap['e']=100;
  // mymap.print_tree();
//
// for(it = mymap.begin(); it != mymap.end();it++)
	// {
	// if ((it.getAddr())->getTop() != 0)
	// std::cout<<*it<<"top = "<<((it.getAddr())->getTop())->getKey()<<std::endl;
	// else
		// std::cout<<*it<<std::endl;
	// }
//
	// mymap['e']=110;
//
   // mymap.print_tree();
	// map<int, int> bst;
	// map<int,int>::iterator it2;
  // for (int i = 0; i < 15; ++i){
    // bst.insert(make_pair(i, i));
//
   // bst.print_tree();
	// for(it2 = bst.begin(); it2 != bst.end();it2++)
	// {
	// if ((it2.getAddr())->getTop() != 0)
	// std::cout<<*it2<<"top = "<<((it2.getAddr())->getTop())->getKey()<<std::endl;
	// else
		// std::cout<<*it2<<std::endl;
	// }
  // }
	// it2 = bst.begin();
	// std::cout << "*it2 = " << *it2 << std::endl;
  // // operator++
  // std::cout << "++it2 = " << *(++it2) << ", now *it2 = " << *it2 << std::endl;
  // // operator++(int)
  // std::cout << "it2++ = " << *(it2++) << ", now *it2 = " << *it2 << std::endl;
  // // operator--
  // std::cout << "--it2 = " << *(--it2) << ", now *it2 = " << *it2 << std::endl;
  // // operator--(int)
  // std::cout << "it2-- = " << *(it2--) << ", now *it2 = " << *it2 << std::endl;
  // // operator==
  // std::cout << "it2 == it2 : " << (it2 == it2) << std::endl;
  // // operator!=
  // //
	// std::cout<<"penis1\n";
  // std::cout << "it2 != it2 : " << (it2 != it2) << std::endl;
//
	// std::cout<<"penis2\n";
// // }
	// std::cout<<"penis\n";
	// test_lower_bound();
	// std::cout<<"test main10\n";
	// for(it2 = mymap.begin(); it2 != mymap.end();it2++)
	// {
	//
	// if ((it2.getAddr())->getTop() != 0)
	// std::cout<<*it2<<"top = "<<((it2.getAddr())->getTop())->getKey()<<std::endl;
	// else
		// std::cout<<*it2<<std::endl;
	// }
	// it2 = mymap.end();
	// std::cout<<"-- 1\n";
	// std::cout<<*--it;
	// std::cout<<"-- 2\n";
	// std::cout<<*--it;
	// std::cout<<"-- 3\n";
	// std::cout<<*--it;
	// std::cout<<"-- 4\n";
	// std::cout<<*--it;
	// std::cout<<"-- 5\n";
	// std::cout<<*--it;
	// std::cout<<"-- 6\n";
	// std::cout<<*it;
	// std::cout<<"test main10\n";
//
	// mymap.print_tree();
	// itlow=mymap.lower_bound ('b');  // itlow points to b
//
	// std::cout<<"test main11 itlow "<<itlow->first<<"\n";
	// itup=mymap.upper_bound ('d');   // itup points to e (not d!)
//
	// std::cout<<"test main11 itup "<<itup->first<<"\n";
//
	// std::cout<<"test main12\n";
//
	// mymap.erase(itlow,itup);        // erases [itlow,itup)
//
	// std::cout<<"test main13\n";
	// // print content:
//
	// mymap.print_tree();
	//
	// map<int,int>  map_c;
	// map<int,int> const map_test;
//
		// map<char,int>::iterator it_test;
//
		// map<int,int>::iterator it;
	// map<int,int>::const_iterator it_c;
	// it_c = map_c.begin();
	// it = it_c;
	// it = it_c;
	// std::cout << it_test->first << " => " << it_test->second << "end ="<<it_test.getEnd()<<'\n';
	// it_test++;
// std::cout << it_test->first << " => " << it_test->second << "end ="<<it_test.getEnd()<<'\n';
	// it_test++;
// std::cout << it_test->first << " => " << it_test->second << "end ="<<it_test.getEnd()<<'\n';
	// it_test++;
		// for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
		// std::cout << it->first << " => " << it->second << '\n';
//
// //
//
	// test();
//
 // test_comparison_iters() ;
	// test_iterator_types();
	// map<char,int>::iterator test1=mymap.end();
	// mymap.print_tree();
	// std::cout<<"test 1 end = "<<test1.getEnd()<<"key "<<test1->first<<std::endl;
	// test1--;
	// std::cout<<"test 1 end = "<<test1.getEnd()<<"key "<<test1->first<<std::endl;
	// test1--;
	// std::cout<<"test 1 end = "<<test1.getEnd()<<"key "<<test1->first<<std::endl;
	// std::cout<<"THE END\n";
//
 // std::cout << "--- Test insert ---" << std::endl;
  // test_insert();
  // std::cout << "--- Test erase ---" << std::endl;
  // test_erase();
  // std::cout << "--- Test swap ---" << std::endl;
  // test_swap();
  // std::cout << "--- Test clear ---" << std::endl;
  // test_clear();
	// std::boolalpha(std::cout);
	// test_only_one_key();
	// std::cout << std::endl;
  // test_container_ordered();
  // std::cout << std::endl;
  // test_iterator_valid();
  // std::cout << std::endl;
  // test_swap_move_only_pointers();
	// test_last();
	}
