#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstddef>
#include <stack>
#include <map>
#ifndef ITERATOR_HPP
#define ITERATOR_HPP
namespace ft
{
	struct random_access_iterator_tag
	{};

	struct rev_random_access_iterator_tag
	{};

	template <class Category, class T, class Distance = ptrdiff_t,
			 class Pointer = T*, class Reference = T&>
				 struct iterator {
					 typedef T         value_type;
					 typedef Distance  difference_type;
					 typedef Pointer   pointer;
					 typedef Reference reference;
					 typedef Category  iterator_category;
				 };

	template <typename T>
		class random_access_iterator :   iterator<random_access_iterator_tag, T>
	{
		typedef typename iterator<random_access_iterator_tag,T>::pointer pointer;
		typedef typename iterator<random_access_iterator_tag,T>::reference reference;
		private:
		pointer elem;
		public:
		typedef typename iterator<random_access_iterator_tag,T>::value_type value_type;
		random_access_iterator(void)
		{
			elem =0;
		}
		random_access_iterator(const random_access_iterator &cpy)
		{
			elem = cpy.elem;
		}
		random_access_iterator(pointer point)
		{
			elem = point;
		}
		random_access_iterator  operator--(int)
		{
			random_access_iterator temp;
			temp.elem = elem ;
			elem -=1;
			return temp;
		}
		friend random_access_iterator operator+( int i, random_access_iterator const it )
		{
			return random_access_iterator (it.elem + i);
		}
		friend random_access_iterator operator+( random_access_iterator const it, int i)
		{
			return random_access_iterator (it.elem + i);
		}

		friend random_access_iterator  operator-(random_access_iterator const it, int i)
		{
			return random_access_iterator(it.elem - i);
		}
		friend int  operator-(random_access_iterator const &it, random_access_iterator const &cpy)
		{
			int i = ((it.elem - cpy.elem));// / sizeof(T);
			// std::cout<<"ici i = "<<i<<std::endl;
			return i ;
		}
		random_access_iterator  &operator++(void)
		{
			elem = elem + 1;
			return *this;
		}
		random_access_iterator  &operator+=(int i)
		{
			elem = elem + i;
			return *this;
		}
		random_access_iterator  &operator-=(int i)
		{
			elem = elem - i;
			return *this;
		}
		random_access_iterator  &operator--(void)
		{
			elem = elem - 1;
			return *this;
		}	
		random_access_iterator  operator++(int)
		{

			random_access_iterator temp;
			temp.elem = elem ;
			elem += 1;
			return temp;
		}	
		reference operator=(const reference cpy)
		{
			elem = cpy.elem;
		}
		reference operator[](int i)
		{
			return (elem[i]);
		}
		bool operator!=(random_access_iterator const & cpy) const
		{
			if (elem == cpy.elem)
				return 0;
			else
				return 1;
		}
		pointer getAddr(void)
		{
			return elem;
		}
		reference operator*(void)
		{
			return *(this->elem) ;
		}
		reference operator->(void)
		{
			return *(this->elem) ;
		}
		// bool operator==(random_access_iterator<const T> &x) const
		// {
		// if (this->elem == x.elem)
		// return 1;
		// else
		// return 0;
		// }
		// bool operator==(random_access_iterator<const T> &x)
		// {
		// if (this->elem == x.elem)
		// return 1;
		// else
		// return 0;
		// }
		// bool operator==(random_access_iterator const& x) const
		// {
		// if (this->elem == x.elem)
		// return 1;
		// else
		// return 0;
		// }
		//
		//
		//
		template <typename S, typename Q>
			friend bool operator<=(random_access_iterator<S> const &x,random_access_iterator<Q> const& y) 
			{
				if (x.elem <= y.elem)
					return 1;
				else
					return 0;
			}
		template <typename S, typename Q>
			friend bool operator<(random_access_iterator<S> const &x,random_access_iterator<Q> const& y) 
			{
				if (x.elem < y.elem)
					return 1;
				else
					return 0;
			}
		template <typename S, typename Q>
			friend bool operator>=(random_access_iterator<S> const &x,random_access_iterator<Q> const& y) 
			{
				if (x.elem >= y.elem)
					return 1;
				else
					return 0;
			}
		template <typename S, typename Q>
			friend bool operator>(random_access_iterator<S> const &x,random_access_iterator<Q> const& y) 
			{
				if (x.elem > y.elem)
					return 1;
				else
					return 0;
			}
		template <typename S, typename Q>
			friend bool operator==(random_access_iterator<S> const &x,random_access_iterator<Q> const& y) 
			{
				if (x.elem == y.elem)
					return 1;
				else
					return 0;
			}
		bool operator!=(random_access_iterator<T> & x)
		{
			if (this->elem == x.elem)
				return 0;
			else
				return 1;
		}
	};

	template <typename T>
		class rev_random_access_iterator : iterator<rev_random_access_iterator_tag, T>
	{
		typedef typename iterator<rev_random_access_iterator_tag,T>::pointer pointer;
		typedef typename iterator<rev_random_access_iterator_tag,T>::reference reference;
		private:
		T *elem;

		public:
		rev_random_access_iterator(void)
		{
			elem =0;
		}
		rev_random_access_iterator(const rev_random_access_iterator &cpy)
		{
			elem = cpy.elem;
		}
		rev_random_access_iterator(T *point)
		{
			elem = point;
		}
		rev_random_access_iterator  operator--(int)
		{
			rev_random_access_iterator temp;
			temp.elem = elem + 1;
			elem +=1;
			return temp;
		}
		rev_random_access_iterator  &operator+(int &i)
		{
			return rev_random_access_iterator(elem + i);
		}
		rev_random_access_iterator  &operator-(int &i)
		{
			return rev_random_access_iterator(elem - i);
		}
		rev_random_access_iterator  &operator-(rev_random_access_iterator &cpy)
		{
			return rev_random_access_iterator((elem - cpy.elem) / sizeof(T));
		}
		rev_random_access_iterator  &operator++(void)
		{

			elem = elem - 1;
			return *this;
		}
		rev_random_access_iterator  &operator--(void)
		{
			elem = elem + 1;
			return *this;
		}	
		rev_random_access_iterator  operator++(int)
		{
			rev_random_access_iterator temp;
			temp.elem = elem -1;
			elem -= 1;
			return temp;
		}	
		reference operator=(const reference cpy)
		{
			elem = cpy.elem;
		}
		bool operator!=(rev_random_access_iterator const & cpy) const
		{
			if (elem == cpy.elem)
				return 0;
			else
				return 1;
		}
		pointer getAddr(void)
		{
			return elem;
		}
		T operator*(void)
		{
			return *(this->elem) ;
		}
		T operator->(void)
		{
			return *(this->elem) ;
		}
		bool operator==(rev_random_access_iterator<T> & x)
		{
			if (this->elem == x.elem)
				return 1;
			else
				return 0;
		}
		bool operator!=(rev_random_access_iterator<T> & x)
		{
			if (this->elem == x.elem)
				return 0;
			else
				return 1;
		}
	};
}
#endif
