
#include <memory>
#include "Iterator.hpp"
#include <iterator>
#include <iostream>

#ifndef VECTOR_HPP
#define VECTOR_HPP
template<typename T, class Allocator = std::allocator<T> >
class vector
{

	private :
		T *t;
		std::allocator<T> _alloc;
		unsigned int _size;
		unsigned int _capacity;
	public:
		typedef T													 value_type;
		typedef Allocator											allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename ft::random_access_iterator<T>				iterator;
		typedef typename ft::random_access_iterator<const T>		const_iterator;
		typedef typename allocator_type::size_type					size_type;
		typedef typename allocator_type::difference_type			difference_type;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef typename ft::rev_random_access_iterator<T>			reverse_iterator;
		typedef typename ft::rev_random_access_iterator<const T>	const_reverse_iterator;
		//ITERATOR 
		const_iterator begin(void) const
		{
			return const_iterator (&t[0]); 
		}
		const_iterator end(void) const
		{
			return const_iterator (t + _size);
		}

		iterator begin(void)
		{
			return iterator (&t[0]); 
		}
		iterator end(void)
		{
			return iterator (t + _size);
		}
		const_reverse_iterator rbegin(void) const
		{
			return const_reverse_iterator (t + _size - 1);
		}
		const_reverse_iterator rend(void) const
		{
			return const_reverse_iterator (t -1);
		}
		reverse_iterator rbegin(void)
		{

			return reverse_iterator (t + _size - 1);
		}
		reverse_iterator rend(void)
		{
			return reverse_iterator (t -1);
		}
		//CONSTRUCTOR
		explicit vector (const allocator_type& alloc = allocator_type())
		{
			// std::cout<<"construcotr vide\n";
			t = 0;
			_size = 0;
			_capacity = 0;
			_alloc = alloc;

			// std::cout<<"construcotr vide end\n";
		}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_size = n;
			_capacity = n;
			t = _alloc.allocate(n);
			for (unsigned int i = 0 ; i < n ; i++)
			{
				_alloc.construct(&t[i],val);
				// t[i] = val;
			}
		}
		// template <class InputIterator>
		vector (iterator first, iterator last,const allocator_type& alloc = allocator_type())
		{
			int i = 0;
			// std::cout<<"taille = "<<first -last<<std::endl;
			_alloc = alloc;
			_size = abs(first-last );
			_capacity=abs(first-last) ;
			t = _alloc.allocate(abs(first - last) );
			while(first < last)
			{
				_alloc.construct(&t[i],*first);
				// std::cout<<"in while "<<*first<<std::endl;
				first++;
				i++;
			}
		}
		vector (const vector& x)
		{
			_size = x._size;
			_capacity = x._capacity;
			t = _alloc.allocate(x._size);
			for (unsigned int i= 0 ; i < x._size; i++)
				_alloc.construct(&t[i],x.t[i]);
			// t[i] = x.t[i];
		}
		//DESTRUCTOR
		~vector()
		{
			if (t != 0)
				clear();
			// _alloc.deallocate(t,_capacity);
			// std::cout<<"destructor\n";
			t = 0;
		}
		//OPERATOR
		vector& operator= (const vector &x)
		{
			// std::cout<<"c'est honteux\n";
			_alloc.deallocate(t, _size);
			t = _alloc.allocate(x._size);
			_size = x._size;
			_capacity = x._capacity;
			for (unsigned int i= 0 ; i < x._size; i++)
				_alloc.construct(&t[i],x.t[i]);
			// t[i] = x.t[i];
			return *this;
		}
		T &operator[](long int d) const
		{
			// std::cout<<"dans [] d = "<<d<<"size = "<<_size<<"\n";
			if (d >= (long int)_size || d < 0 )
				throw std::exception();
			// std::cout<<"dans [] return ok = "<<t[d]<<"\n";
			return t[d];
		}
		T &operator[](long int d)
		{
			// std::cout<<"dans [] d = "<<d<<"size = "<<_size<<"\n";
			if (d >= (long int)_size || d < 0 )
				throw std::exception();
			// std::cout<<"dans [] return ok = "<<t[d]<<"\n";
			return t[d];
		}
		//CAPACITY
		size_type capacity() const
		{
			return _capacity;
		}
		unsigned int size() const
		{
			return _size;
		}

		unsigned int max_size() const throw()
		{
			return _alloc.max_size();
		}
		void resize (size_type n, value_type val = value_type())
		{
			unsigned int i;
			T *temp = _alloc.allocate(n);
			for(i = 0 ; i < _size && i < n ; i ++)
			{
				_alloc.construct(&temp[i],t[i]);
				// temp[i] = t[i];
			}
			_alloc.deallocate(t,_capacity);
			t = 0;
			if (n >= _size)
			{
				for (i = 0 ; _size + i < n; i++)
				{
					_alloc.construct(&temp[_size + i],val);
					// temp[_size + i]=val;
				}
			}
			t = temp;
			_size = n;
			_capacity = n;
		}
		bool empty() const
		{
			if (_size == 0)
				return 1;
			else
				return 0;
		}
		void reserve (size_type n)
		{

			if  (n >max_size())
				throw std::exception();
			if (n > _capacity)
			{

				T *temp;
				temp = _alloc.allocate(n);
				if (t != 0)
				{
					for (unsigned int i = 0 ; i < _size; i++)
						temp[i] = t[i];
					_alloc.deallocate(t,_size);
				}
				_capacity = n;
				t = temp;
			}
		}
		void	printV(void)
		{
			for ( unsigned int i = 0; i < _size ; i++)
			{
				// std::cout<<t[i]<<std::endl;
			}
		}
		//ELEMENT ACCESS
		T& at (size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("vector");
			return t[n];
		}
		const_reference at (size_type n) const
		{
			if (n >= _size)
				throw std::exception();
			return t[n];
		}
		T&  front()
		{
			return t[0];
		}
		T& front() const
		{
			return t[0];
		}
		T&  back()
		{
			return t[_size-1];
		}
		T& back() const
		{
			return t[_size-1];
		}
		//MODIFIER
		void dealloc_destruct(void)
		{
			if (t!= 0)
			{
				for (unsigned int i = 0; i < _size;i++)
				{
					_alloc.destroy(&t[i]);
				}
				_alloc.deallocate(t,_capacity);
			}
		}
		void assign (iterator first, iterator last)
		{
			iterator temp = first;

			// while (first != last)
			// {
			// i++;
			// first++;
			// }

			if (t != 0)
				dealloc_destruct();
			_size = abs(first-last);
			_capacity =_size; 
			// std::cout<<"dans assign size = "<<_size<<std::endl;
			// _alloc.deallocate(t,_size);
			t = _alloc.allocate(_size);
			for(unsigned int j = 0; j < _size ; j++)
			{
				_alloc.construct(&t[j],*temp);
				// t[j] = *temp;
				temp++;
			}
		}
		void assign (size_type n, const value_type& val)
		{
			// std::cout<<"in n val assign\n";
			if (t != 0)
				dealloc_destruct();
			// _alloc.deallocate(t,_capacity);
			t = _alloc.allocate(n);
			for(unsigned int j = 0; j < n ; j++)
			{

				_alloc.construct(&t[j],val);
				// t[j] = val;
			}
			_size = n;
			_capacity = n;
		}
		void push_back (const value_type& val)
		{
			// std::cout<<"push back 7=\n";
			if (_size  + 1< _capacity)
			{
				// std::cout<<"push back 1 size = "<<_size<<" "<<_capacity<<"\n";
				// t[_size] = val;
				_alloc.construct(&t[_size],val);	
				_size++;
			}
			else
			{
				T *temp;
				if (t != 0)
				{
					// std::cout<<"push back 6="<<_size *2<<"\n";
					temp = _alloc.allocate(_size *2);
					for (unsigned int i = 0 ; i < _size ; i++)
					{
						_alloc.construct(&temp[i],t[i]);
						// temp[i] = t[i];
					}

					// temp[_size] = val;
					_alloc.construct(&temp[_size],val);
					// _alloc.deallocate(t,_capacity);
					dealloc_destruct();
					_capacity = _size * 2;
					_size++;
					t=0;
					t = temp;

					// std::cout<<"push back 111!"<<_size<<"\n";

					// _alloc.construct(&temp[_size],val);
					// std::cout<<t[10]<<"push back 10!\n";
				}
				else
				{

					// std::cout<<"push back 5=10!\n";
					t = _alloc.allocate(10);
					_size =1;
					_capacity = 10;
					_alloc.construct(&t[0],val);

					// std::cout<<"push back 7"<<t[1]<<"\n";
					// temp[0] = val;
				}
			}
		}
		void pop_back()
		{
			_alloc.destroy(&t[_size -1 ]);
			_size--;
		}
		iterator insert (iterator position, const value_type& val)
		{

			int i = 0;
			// std::cout<<"test 1 "<<_size<<" "<<_capacity<<"\n";
			iterator iv;
			iterator r;
			if (_size < _capacity)
			{

				// std::cout<<"test 2\n";
				i = _size ;
				for (iterator it = end(); it != position ;it --)
				{

					// std::cout<<"test f="<<i<<"\n";
					// t[i] = t[i-1];
					_alloc.construct(&t[i],t[i-1]);
					_alloc.destroy(&t[i-1]);
					i--;
				}

				// std::cout<<"test f2\n";
				r = &t[i];
				t[i] = val;

				// std::cout<<"test f3\n";
				_alloc.construct(&t[i],val);
				_size++;
			}
			else
			{

				// std::cout<<"test 3\n";
				T *temp;
				if (t != 0)
				{
					temp = _alloc.allocate(_size *2);
					for (iterator it = begin(); it != position ;it ++)
					{
						_alloc.construct(&temp[i],*it);
						// std::cout<<"ici" <<temp[i]<<std::endl;
						i++;
					}
					r = &temp[i];
					_alloc.construct(&temp[i],val);

					i++;
					for (iterator it = position; it != end() ;it ++)
					{
						_alloc.construct(&temp[i],*it);

						// std::cout<<"icila" <<temp[i]<<std::endl;
						i++;
					}
					_alloc.deallocate(t,_capacity);
					_capacity = _size * 2;
					_size++;
				}
				else
				{

					// std::cout<<"test 4\n";
					temp = _alloc.allocate(10);
					_size =1;
					_capacity = 10;
					_alloc.construct(&temp[0],val);
					// temp[0] = val;
					r = &temp[0];
				}
				t = temp;
			}
			// std::cout<<"insert size is "<<_size<<std::endl;
			return r;

		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			int i = 1;

			if (n +_size > _capacity)
			{

				// std::cout<<"derch 1\n";
				T* temp  = _alloc.allocate(_size + n);
				for (iterator it = end()-1; it >= position; it--)
				{

					// std::cout<<"derch 3 "<<_size<<" "<<n<<" "<<i<<"\n";
					_alloc.construct(&temp[_size + n - i],*it);
					// temp[_size +n - i] = *it;
					i++;
				}
				for (unsigned int x = 0; x < n; x++)
				{

					// std::cout<<"derch 4\n";
					_alloc.construct(&temp[_size + n - i],val);
					// temp[_size +n - i] = val;
					i++;
				}
				for (unsigned int x = 0 ; x <= _size + n -i; )
				{

					// std::cout<<"derch 5\n";
					_alloc.construct(&temp[x],t[x]);
					// temp[x] = t[x];
					x++;
				}
				dealloc_destruct();
				_size = _size + n;
				_capacity = _size;
				t = temp;
			}
			else
			{

				// std::cout<<"derch 2\n";
				for (iterator it = end() - 1; it >= position; it--)
				{

					// std::cout<<"derch 7 = "<<abs(begin()-it) + n <<"\n";
					_alloc.construct(&t[abs(begin()-it)+n] ,*it);
					_alloc.destroy(it.getAddr());	
					// *(it + n) = *it;
				}
				for (unsigned int x = 0; x < n; x++)
				{

					// std::cout<<"derch 8 x = "<<x<<" pos = "<<*position<<"\n";
					_alloc.construct(&t[abs(begin()-position) +x ] ,val);
					// *position = val;
					// std::cout<<"derch 11 x = "<<x<<"\n";
					// std::cout<<"derch 10 x = "<<x<<"\n";
				}

				// std::cout<<"derch 9\n";
				_size = _size + n;
			}
		}
		void insert (iterator position, iterator first, iterator last)
		{

			// std::cout<<"penis8\n";
			int i = 1;
			unsigned int n = abs(first - last ) ;

			// std::cout<<"penis8n = "<<n<<"\n";
			// std::cout<<"penis1\n";
			if (n +_size > _capacity)
			{

				// std::cout<<"penis2\n\n\n\n\n\n";
				T* temp  = _alloc.allocate(_size + n);
				for (iterator it = end(); it >= position; it--)
				{
					// temp[_size +n - i] = *it;
					_alloc.construct(&temp[_size +n - i],*it);
					i++;
				}
				last--;
				for (; last >= first; last--)
				{
					// temp[_size +n - i] = *last;

					_alloc.construct(&temp[_size +n - i],*last);
					i++;
				}
				for (unsigned int x = 0 ; x<= _size +n - i; )
				{
					// temp[x] = t[x];

					_alloc.construct(&temp[x],t[x]);
					x++;
				}
				dealloc_destruct();
				t = temp;
				_size = _size + n;
				_capacity = _size + n;
			}
			else
			{

				// std::cout<<"penis3\n\n\n\n\n\n";
				// std::cout<<_capacity<<"penis3\n";
				for (iterator it = end()-1; it >= position; it--)
				{

					// std::cout<<(it + n).getAddr()<<" penis4 "<<_capacity<<"\n";
					// *(it +n ) = *it;

					_alloc.construct(&t[abs(begin()-it) + n],*it);
					_alloc.destroy(it.getAddr());
				}

				for (int x = 0; first < last; first++) 
				{

					// std::cout<<"penis5\n";

					_alloc.construct(&t[abs(begin()-position) + x],*first);

					// _alloc.destroy(first.getAddr());
					x++;
				}
				_size = _size + n;
			}
		}
		void clear()
		{
			for (unsigned int i = _size-1; i>=0 && _size != 0; i--)
			{
				// std::cout<<"dan for clear\n";
				_alloc.destroy(&t[i]);
				if (i == 0)
					break;
			}
			_alloc.deallocate(t,_capacity);
			t=0;
			_size = 0;
			_capacity = 0;
		}
		friend void swap(vector &x, vector &y)
		{
			T* temp = x.t;
			unsigned int s_temp = x._size;
			unsigned int c_temp = x._capacity;
			x.t = y.t;
			x._size = y._size;
			x._capacity = y._capacity;
			y.t = temp;
			y._size = s_temp;
			y._capacity = c_temp;
		}
		void swap (vector& x)
		{
			T* temp = t;
			unsigned int s_temp = _size;
			unsigned int c_temp = _capacity;
			t = x.t;
			_size = x._size;
			_capacity = x._capacity;
			x.t = temp;
			x._size = s_temp;
			x._capacity = c_temp;
		}
		//non member overload relation mon cul

		friend bool operator==(vector const &x, vector const &y) 
		{
			if (x.size() != y.size())
				return 0;
			for(unsigned int i = 0; i < x.size();i++)
			{
				if(x[i]!= y[i])
					return 0;
			}
			return 1;
		}
		friend bool operator!=(vector const &x, vector const &y)
		{
			return (!(x==y));
		}

		friend bool operator>(vector const &x, vector const &y)
		{
			for (unsigned int i = 0; i <x.size() && i <y.size();i++)
			{
				if (x[i] < y[i])
					return 0;
				if (y[i] > x[i])
					return 1;
			}
			if (x.size()<=y.size())
				return(0);
			return 1;
		}
		friend bool operator<(vector const &x, vector const &y)
		{
			for (unsigned int i = 0; i <x.size() && i <y.size();i++)
			{
				if (y[i] > x[i])
					return 1;
				if (x[i] > y[i])
					return 0;
			}
			if (x.size()>=y.size())
				return (0);
			return 1;
		}
		friend bool operator<=(vector const &x, vector const &y)
		{
			return !(y<x);
		}
		friend bool operator>=(vector const &x, vector const &y)
		{
			return !(x<y);
		}
};
#endif
