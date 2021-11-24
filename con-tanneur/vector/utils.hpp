#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>

#include <type_traits>
#include <functional>
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
template <class A, class B, class C=std::false_type, class D = std::false_type, class E = std::false_type,class F = std::false_type>
struct Or {
	typedef std::true_type value;
};

template <>
struct Or<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type> 
{typedef std::false_type value;
};

template <class A, class B>
struct Ehhhehh{
	typedef std::false_type value;
	static const bool value2=1;
};

template <>
struct Ehhhehh<std::true_type, std::true_type>{
	typedef std::true_type value;
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


#endif
