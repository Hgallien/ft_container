#include "vector.hpp"

	template <typename T>
void	test_constructor_assignastion()
{

	std::cout<<"////////////Test constructor/////////////////\n";
	vector<T> v_base(100,42);
	std::cout<<"Size = "<<v_base.size()<<std::endl;
	v_base.reserve(1000);
	std::cout<<"Capacity= "<<v_base.capacity()<<std::endl;
	std::cout<<"Empty= "<<v_base.empty()<<std::endl;

	std::cout<<"Test constructor n & val\n";
	for(typename  vector<T>::iterator it = v_base.begin();it!= v_base.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";
	vector<T> v_iterator(v_base.begin(),v_base.end());
	v_base.clear();

	std::cout<<"Test constructor iterator\n";
	for(typename vector<T>::iterator it = v_base.begin();it!= v_base.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";
	vector<T> v_copy(v_iterator);
	for(typename vector<T>::iterator it = v_iterator.begin();it!= v_iterator.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";
	vector<T> v_ass = v_copy;

	std::cout<<"Test constructor copy\n";
	for(typename vector<T>::iterator it = v_ass.begin();it!= v_ass.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";

	std::cout<<"Test constructor vide\n";
	vector<T> v_base_e;
	std::cout<<"Size = "<<v_base.size()<<std::endl;
	std::cout<<"Capacity= "<<v_base.capacity()<<std::endl;
	std::cout<<"Empty= "<<v_base.empty()<<std::endl;
	for(typename vector<T>::iterator it = v_base_e.begin();it!= v_base_e.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";
	vector<T> v_iterator_e(v_base_e.begin(),v_base.end());
	v_base_e.clear();
	for(typename vector<T>::iterator it = v_iterator_e.begin();it!= v_iterator_e.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";

	vector<T> v_copy_e(v_iterator_e);
	for(typename vector<T>::iterator it = v_iterator_e.begin();it!= v_iterator_e.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";

	vector<T> v_ass_e = v_copy_e;
	for(typename vector<T>::iterator it = v_ass_e.begin();it!= v_ass_e.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";
}

	template <typename T>
void	test_iterator()
{
	vector<T> v;
	typename vector<T>::iterator it = it.begin();
	for (int i = 0 ; i<100; i++)
	{
			v.insert(i);
	}
	std::cout << "*it = " << *it << std::endl;
  // operator++
  std::cout << "++it = " << *(++it) << ", now *it = " << *it << std::endl;
  // operator++(int)
  std::cout << "it++ = " << *(it++) << ", now *it = " << *it << std::endl;
  // operator--
  std::cout << "--it = " << *(--it) << ", now *it = " << *it << std::endl;
  // operator--
  std::cout << "it-- = " << *(it--) << ", now *it = " << *it << std::endl;
  // operator[]
  std::cout << "it[0] = " << it[0] << ", it[2] = " << it[2] << std::endl;
  // operator+=
  std::cout << "it += 2, now *it = " << *(it += 2) << std::endl;
  // operator-=
  std::cout << "it -= 1, now *it = " << *(it -= 1) << std::endl;
  // operator-
  std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
  // operator+
  std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
  // operator+
  std::cout << "*(1 + it) = " << *(1 + it) << std::endl;
  // operator-
  std::cout << "*(it - (it + 2)) = " << (it - (it + 2)) << std::endl;
  std::cout << "*(it - (it - 1)) = " << (it - (it - 1)) << std::endl;
  // operator==
  std::cout << "it == it : " << (it == it) << std::endl;
  std::cout << "it == (it + 1) : " << (it == (it + 1)) << std::endl;
  // operator!=
  std::cout << "it != (it + 1) : " << (it != (it + 1)) << std::endl;
  std::cout << "it != it : " << (it != it) << std::endl;
  // operator<
  std::cout << "it < it : " << (it < it) << std::endl;
  std::cout << "it < (it + 1) : " << (it < (it + 1)) << std::endl;
  // operator>
  std::cout << "it > it : " << (it > it) << std::endl;
  std::cout << "it > (it - 1) : " << (it > (it - 1)) << std::endl;
  // operator<=
  std::cout << "it <= it : " << (it <= it) << std::endl;
  std::cout << "it <= (it + 1) : " << (it <= (it + 1)) << std::endl;
  // operator>=
  std::cout << "it >= it : " << (it >= it) << std::endl;
  std::cout << "it >= (it - 1) : " << (it >= (it - 1)) << std::endl;
  std::cout << "(it + 3) - it = " << (it + 3) - it << std::endl;
	

  std::cout << "Mutable iterator" << std::endl;
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << ", ";
  std::cout << "END" << std::endl;

  std::cout << "Mutable reverse iterator" << std::endl;
  for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
    std::cout << *it << ", ";
  std::cout << "END" << std::endl;

  vector<int> const cIntVect(v);
  std::cout << "Const iterator" << std::endl;
  for (vector<int>::const_iterator it = cIntVect.begin(); it != cIntVect.end(); ++it)
    std::cout << *it << ", ";
  std::cout << "END" << std::endl;

  std::cout << "Reverse const iterator" << std::endl;
  for (vector<int>::const_reverse_iterator it = cIntVect.rbegin(); it != cIntVect.rend(); ++it)
    std::cout << *it << ", ";
  std::cout << "END" << std::endl;
}

void all_comparisons(vector<int> const & a, vector<int> const & b) {
  std::boolalpha(std::cout);
  std::cout << "a = ";
  std::cout << ", b = ";
  std::cout << std::endl;
  std::cout << "a == b : " << (a == b) << std::endl;
  std::cout << "a != b : " << (a != b) << std::endl;
  std::cout << "a < b : " << (a < b) << std::endl;
  std::cout << "a > b : " << (a > b) << std::endl;
  std::cout << "a >= b : " << (a >= b) << std::endl;
  std::cout << "a <= b : " << (a <= b) << std::endl;
}

template<typename T>
void	print_vect(vector<T> v)
{
	for(typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout<<*it<<" ";
	}
		std::cout<<"\n";
}
void test_comparisons() {
  
	vector<int> v1;

	vector<int> v1_b;

	vector<int> v2;
	vector<int> v2_b;
	vector<int> v3;
	vector<int> v3_b;
	for (int i = 0 ; i < 4 ; i++)
	{	v1.push_back(i);
		v1_b.push_back(i);
	}
	int v1b_values[] = {0, 1, 2, 3};
  int v2_values[] = {0, 1, 2, 3, 4};
  int v2b_values[] = {0, 1, 2};
  	for (int i = 0 ; i < 5 ; i++)
	{	v2.push_back(i);
	}
for (int i = 0 ; i < 3 ; i++)
	{	v2_b.push_back(i);
	}
  int v3_values[] = {0, 1, 10};
		v3.push_back(0);
		v3.push_back(1);
		v3.push_back(10);
  int v3b_values[] = {0, 1, 1};
  		v3.push_back(0);
		v3.push_back(1);
		v3.push_back(1);
  all_comparisons(v1, v1_b);
  all_comparisons(v1, v2);
  all_comparisons(v1, v2_b);
  all_comparisons(v1, v3);
  all_comparisons(v1, v3_b);
}

template <typename T>
void	test_insertion()
{

	std::cout<<"/////////////////Test modifiers  & access////////////////\n";
	vector<T> v_b;

	std::cout<<"Test insert \n";
	for (int i = 0 ; i < 100000 ; i++)
	{
		v_b.insert(i);
	}
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";

	std::cout<<"Test push_back \n";
	for (int i = 0 ; i < 100 ; i ++)
	{
		v_b.push_back(i);
	}
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";

	std::cout<<"Test pop_back \n";
	for (int i = 0 ; i < 100 ; i ++)
	{
		v_b.pop_back(i);
	}
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";

	std::cout<<"Test erase one\n";
	v_b.erase(v_b.begin());
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";

	v_b.erase(v_b.begin(), v_b.end() -1000);

	std::cout<<"Test erase range\n";
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";

	std::cout<<"Test operator[] \n";
	for (unsigned int i = 0 ; i <v_b.size;i++)
	{
		std::cout<<v_b[i]<<" ";
	}
	std::cout<<"\n";
	
	std::cout<<"Test swap \n";
	vector<T> swapy(4,4);
	v_b.swap(swapy);
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";
	for(typename  vector<T>::iterator it = swapy.begin();it!= swapy.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";
	
	std::cout<<"Test swap vide\n";
	v_b.swap(swapy);
	vector<T> vide;
	v_b.swap(vide);
	for(typename  vector<T>::iterator it = v_b.begin();it!= v_b.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<"\n";
	
	for(typename  vector<T>::iterator it = vide.begin();it!= vide.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	v_b.swap(vide);

	std::cout<<"Test front\n";
	std::cout<<v_b.front();

	std::cout<<"Test AT\n";
	std::cout<<v_b.at(100);

	std::cout<<"Test AT\n";
	std::cout<<v_b.back();

}
