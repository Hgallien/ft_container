#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>

#include <functional>
template <class Key , class T>
struct pair
{
	Key first;
	T second;
	
	pair (const  Key& k) : first (k)
	{
	}
	pair (const  Key& k, const T& elem) : first (k), second(elem)
	{
		// std::cout<<"penis magique\n";
	}
	pair ( pair const &cpy)  : first(cpy.first), second(cpy.second)
	{
	}
	pair()
	{
		first = 0;
		second = 0;
	}
	template<class Key2, class T2>
	pair(const pair<Key2, T2>& other) : first(other.first), second(other.second)
	{
	}

	pair& operator=(pair const cpy)
	{
	  first =  cpy.first;
	  second=  cpy.second;
		return *this;
	// return pair(cpy);
	}
	
	const Key& getF() const {
		return first;
	}
};
template <class T1, class T2>
  pair<T1,T2> make_pair (T1 x, T2 y)
{
		return (pair<T1,T2>(x,y));
}

template <class Key, class T>
std::ostream& operator<<(std::ostream& out, const pair<Key,T> &w)
{
	out <<"("<<w.first<<") "<<"("<<w.second<<")\n";
	return out;
}
template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
  while (first1!=last1)
  {
    if (first2==last2 || *first2<*first1) return false;
    else if (*first1<*first2) return true;
    ++first1; ++first2;
  }
  return (first2!=last2);
}
template <class InputIterator1, class InputIterator2, class Compare>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp)
{
  while (first1!=last1)
  {
    if (first2==last2 || !comp(*first2,*first1)) return false;// *first2<*first1) return false;
    else if (comp(*first1,*first2)) return true;//(*first1<*first2) return true;
    ++first1; ++first2;
  }
  return (first2!=last2);
}

template<class T, class U>
struct is_same {
	typedef std::false_type value;
};
 
template<class T>
struct is_same<T, T> {
	typedef std::true_type value;
};

template <class Cond, class T = void>
struct enable_if
{};

template <class T>
struct enable_if<std::true_type, T>
{
	typedef T		type;
};
template <class A, class B, class C=std::true_type, class D = std::true_type, class E = std::true_type,class F = std::true_type>
struct Or {
	typedef std::true_type value;
};

template <>
struct Or<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type> {
	typedef std::false_type value;
};

template <class T> 
struct is_integral  
{
	typedef  std::false_type value;
};

template <>
struct is_integral<bool>
{

	typedef  std::true_type value;
};
template <>
struct is_integral<char>
{

	typedef  std::true_type value;
};
template <>
struct is_integral<char16_t>
{
	typedef  std::true_type value;
};
template <>
struct is_integral<char32_t>
{
	typedef  std::true_type value;
};
template <>
struct is_integral<wchar_t>
{
	typedef  std::true_type value;
};
template <>
struct is_integral<signed char>
{
	typedef  std::true_type value;
};
template <>
struct is_integral<short int>
{
	typedef  std::true_type value;
};
template <>
struct is_integral<int>
{
	typedef  std::true_type value;
};
template <>
struct is_integral<long int>
{
	typedef  std::true_type value;
};
template <>
struct is_integral<long long int>
{
	typedef  std::true_type value;
};

template <>
struct is_integral<unsigned char>
{
	typedef  std::true_type value;
};
template <>
struct is_integral<unsigned short int>
{
	typedef  std::true_type value;
};
template <>
struct is_integral<unsigned int>
{
typedef  std::true_type value;
};
template <>
struct is_integral<unsigned long int>
{
	typedef  std::true_type value;
};
template <>
struct is_integral<unsigned long long int>
{
	typedef  std::true_type value;
};


#endif
