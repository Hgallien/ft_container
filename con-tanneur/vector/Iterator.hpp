#include <iostream>
#include <cstdlib>
#include <cstddef>
namespace ft
{
	struct input_iterator_tag
	{};
	struct forward_iterator_tag
	{};
	struct random_access_iterator_tag
	{};
	struct bidirectional_iterator_tag
	{};
	struct rev_random_access_iterator_tag
	{};
	template <class Iterator> class iterator_traits
	{
		
			typedef typename Iterator::value_type value_type;
			typedef typename  Iterator::difference_type difference_type;
			typedef typename  Iterator::pointer pointer;
			typedef typename  Iterator::reference reference;
			typedef typename  Iterator::iterator_category iterator_category;
	};
	template <class T> class iterator_traits<T*>
	{
			typedef  T value_type;
			typedef ptrdiff_t difference_type;
			typedef	T*	pointer;
			typedef T&	reference;
			typedef random_access_iterator_tag iterator_category;
	};
	template <class T> class iterator_traits<const T*>
	{
			typedef  const T value_type;
			typedef ptrdiff_t difference_type;
			typedef	const T*	pointer;
			typedef const T&	reference;
			typedef random_access_iterator_tag iterator_category;	
	};
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
		class random_access_iterator :    public iterator_traits<iterator<random_access_iterator_tag, T> >
	{
		public:
		typedef typename iterator<random_access_iterator_tag,T>::pointer pointer;
		typedef typename iterator<random_access_iterator_tag,T>::reference reference;
		typedef typename iterator<random_access_iterator_tag,T>::value_type value_type;
		private:
		pointer elem;
		public:
		random_access_iterator(void)
		{
			elem =0;
		}
		random_access_iterator(const random_access_iterator &cpy)
		{
			elem = cpy.elem;
		}

		template <typename T2>
		random_access_iterator(const random_access_iterator<T2> &cpy) : elem(cpy.operator->())
		{ }

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
		template<typename S>	
		random_access_iterator &operator=(random_access_iterator<S> cpy)
		{
			elem = (cpy.operator->());
			return *this;
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
		pointer operator->(void) const
		{
			return (this->elem) ;
		}

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

		template <typename S, typename Q>
		friend bool operator!=(random_access_iterator<S> const &x,random_access_iterator<Q> const& y) 
		{
			if (y.elem == x.elem)
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
		typedef  random_access_iterator<T> iterator;
		private:
		// T *elem;
		iterator it;
		public:
		rev_random_access_iterator(void)
		{
			// elem =0;
			it = 0;
		}
		rev_random_access_iterator(const rev_random_access_iterator &cpy)
		{
			// elem = cpy.elem;
			it = cpy.it;
		}
		rev_random_access_iterator(T *point)
		{
			// elem = point;
			it = iterator(point);
		}
		rev_random_access_iterator  operator--(int)
		{
			rev_random_access_iterator temp = *this;
			it++;
			return temp;
			// rev_random_access_iterator temp;
			// temp.elem = elem + 1;
			// elem +=1;
			// return temp;
		}
		reference operator[](int i )
		{
			return it[i];
		}
		rev_random_access_iterator  &operator+(int &i)
		{
			// return rev_random_access_iterator(elem + i);
			return it - i;
		}
		rev_random_access_iterator  &operator-(int &i)
		{
			return it + i;
			// return rev_random_access_iterator(elem - i);
		}
		rev_random_access_iterator  &operator-(rev_random_access_iterator &cpy)
		{

			return it - cpy.it;
			// return rev_random_access_iterator((elem - cpy.elem) / sizeof(T));
		}
		rev_random_access_iterator  &operator++(void)
		{
			--it;
			return *this;
			// elem = elem - 1;
			// return *this;
		}
		rev_random_access_iterator  &operator--(void)
		{
			++it;
			return *this;
			// elem = elem + 1;
			// return *this;
		}
		iterator base() const
		{
			return it;
		}
		rev_random_access_iterator  operator++(int)
		{
			rev_random_access_iterator temp = *this;
			it--;
			return temp;
			// rev_random_access_iterator temp;
			// temp.elem = elem -1;
			// elem -= 1;
			// return temp;
		}	
		reference operator=(const reference cpy)
		{
			it = cpy;
			// elem = cpy.elem;
		}
		bool operator!=(rev_random_access_iterator const & cpy) const
		{
			return it != cpy.it;
			// if (elem == cpy.elem)
				// return 0;
			// else
				// return 1;
		}
		pointer getAddr(void)
		{
			return it.elem;
		}
		T operator*(void)
		{
			return *it;
			// return *(this->elem) ;
		}
		T operator->(void)
		{
			return it->elem;
			// return *(this->elem) ;
		}
		bool operator==(rev_random_access_iterator<T> & x)
		{
			return it == x.it;
			// if (this->elem == x.elem)
				// return 1;
			// else
				// return 0;
		}
		bool operator!=(rev_random_access_iterator<T> & x)
		{
			return it != x.it;
			// if (this->elem == x.elem)
				// return 0;
			// else
				// return 1;
		}
	};
}
