#ifndef ITERATORM_HPP
#define ITERATORM_HPP
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "utils.hpp"
namespace ft
{
	struct random_access_iterator_tag
	{};
	struct bidirectional_iterator_tag
	{};
	struct rev_bidirectional_iterator_tag
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

	template <  typename  T,class Key,class mapped,class fpair,class Compare = std::less< Key> > 
		class bidirectional_iterator :   iterator_traits<iterator<bidirectional_iterator_tag, T> >
	{
		public:
		typedef typename iterator<bidirectional_iterator_tag,T>::pointer pointer;
		typedef typename iterator<bidirectional_iterator_tag,T>::reference reference;
		typedef typename iterator<bidirectional_iterator_tag,T >::value_type value_type;
		private:
		pointer elem;
		bool end;
		public :
		bool getEnd()
		{
			return end;
		}
		bidirectional_iterator(void)
		{
			elem =0;
			end = 0;
		}
		bidirectional_iterator(const bidirectional_iterator &cpy)
		{
			elem = cpy.elem;
			end = cpy.end;
		}
		bidirectional_iterator(pointer point, bool e = 0)
		{
			elem = point;
			end =e; 
		}
		bidirectional_iterator  operator--(int)
		{
			// std::cout<<"--void key == "<<elem->getKey()<<"end = "<< end<<"\n";
			pointer temp = elem;
			if (end == 1)
			{
				end = 0;
				return temp;
			}
			if (elem->getLeft() != NULL)
			{
				elem = elem->getLeft();
				while (elem->getRight() != NULL)
				{
					elem = elem->getRight();
				}
				return temp;
			}
			else 
			{


				// std::cout<<"--void key top ="<< elem->getTop()->getKey()<<" "<<"content = "<<elem->getTop()->getContent()<<elem->getKey()<<"\n";
				if (elem->getTop() != 0 && Compare()(elem->getTop()->getKey(),elem->getKey()))
				{

				// std::cout<<"--void key top  out 1="<<std::endl;
					elem= elem->getTop();
					return temp;
				}
				while (!(Compare()(elem->getKey() , temp->getKey())))
				{

				// std::cout<<"--void key top  while"<<std::endl;
					elem = elem->getTop();
				}

				// std::cout<<"--void key top  out 2="<<std::endl;
				return temp ;
			}
		}
		// bidirectional_iterator  operator--(int)
		// {
//
			// std::cout<<"--int\n";
			// pointer temp = elem;
			// if (elem->getLeft() != NULL)
			// {
				// elem = elem->getLeft();
				// while (elem->getRight() != NULL)
				// {
					// elem = elem->getRight();
				// }
				// return temp;
			// }
			// else
			// {
				// // while (   (elem->getTop())->getKey() > elem->getKey())
				// while (!(Compare()((elem->getTop())->getKey() , elem->getKey())))
				// {
					// elem = elem->getTop();
				// }
				// return temp;
			// }
		// }
		bidirectional_iterator  &operator++(void)
		{
			// std::cout<<"\n++ void in = "<<elem->getKey()<<"\n";
			pointer temp=elem;
			pointer temp2=elem;
			while (temp2->getTop() != 0)
			{
				temp2 = temp2->getTop();
			}
			while (temp2->getRight()!= 0)
				temp2= temp2->getRight();
			if (temp2 == temp)
			{
				end =1;
				return *this;
			}
			if (temp->getRight() != 0)
			{


			// std::cout<<"++ void right != NULL"<<elem->getKey()<<"\n";
				// std::cout<<"++ void right != NULL"<<elem->getKey()<<"\n";
				temp = temp->getRight();

				// std::cout<<"++ void right != NULL"<<temp->getKey()<<"\n";
				while (temp->getLeft() != 0)
				{

					// std::cout<<"++ void right != NULL While temp ="<< temp->getKey()<<"left = "<<(temp->getLeft())->getKey()<<"\n";
					temp = temp->getLeft();
				}
				elem = temp;

			// std::cout<<"out right!= 0 :"<<elem->getKey()<<"\n";
				return *this;
			}
			else 
			{
				if (temp->getTop() == 0)
				{

					elem = temp;
					end = 1;

			// std::cout<<"out right== 0 top == 0 :"<<elem->getKey()<<"\n";
					return *this;
				}
				if (!(Compare()(temp->getTop()->getKey(),temp->getKey())))
					{
						temp = temp->getTop();
						elem = temp;

			// std::cout<<"out right== 0 first if :"<<elem->getKey()<<"\n";
						return *this;
					}
				while (Compare()((temp->getTop())->getKey() , temp->getKey()))
				{

					temp = temp->getTop();
					// std::cout<<"++ void right-- NULL"<<temp->getKey()<<"\n";
					if (temp->getTop())
						// std::cout<<"temp top key = "<<(temp->getTop())->getKey()<<"\n";
					if (temp->getTop() == 0)
					{

						//elem = temp;
						// std::cout<<"sortie end\n";
						end = 1;

			// std::cout<<"out right== 0 first end dans while : "<<elem->getKey()<<"\n";
						return *this;
					}

				}

					temp = temp->getTop();
				elem = temp;

			// std::cout<<"out right== 0 last: "<<elem->getKey()<<"\n";
				return *this;
			}
		}
		bidirectional_iterator  &operator--(void)
		{
			// std::cout<<"--void "<<elem->getKey()<<"\n";
			if (end == 1)
			{
				end = 0;
				return *this;
			}
			if (elem->getLeft() != NULL)
			{
				elem = elem->getLeft();
				while (elem->getRight() != NULL)
				{
					elem = elem->getRight();
				}
				return *this;
			}
			else 
			{


				// std::cout<<"--void key top ="<< elem->getTop()->getKey()<<" "<<elem->getKey()<<"\n";
				if (elem->getTop() != 0 && Compare()(elem->getTop()->getKey(),elem->getKey()))
				{
					elem= elem->getTop();
					return *this;
				}
				while (!(Compare()((elem->getTop())->getKey() , elem->getKey())))
				{
					elem = elem->getTop();
				}
				return *this;
			}


			return *this;
		}	
		bidirectional_iterator  operator++(int)
		{
			// std::cout<<"bidirectoal ++ int\n";
			pointer temp = elem;	
			pointer temp2 = elem;	
			if (temp2->getRight() != NULL)
			{

				// std::cout<<"bidirectoal ++ int  right != 0\n";
				temp2 = temp2->getRight();
				while (temp2->getLeft() != NULL)
				{
					temp2 = temp2->getLeft();
				}
				elem = temp2;
				return temp;
			}
			else 
			{

				// std::cout<<"tamere la timpe ==0\n";
				if (temp->getTop() == 0)
				{

					// std::cout<<"temp->getTop ==0\n";

					end = 1;
					return temp2;
				}

				temp = temp->getTop();
				// while (Compare()((temp->getTop())->getKey() , temp->getKey()))
				
				 while (Compare()(temp->getKey() ,elem->getKey()))
				{

					// std::cout<<"++ void right == NULL"<<temp->getKey()<<"\n";
					if (temp->getTop() == 0)
					{

						// elem = temp;
						end = 1;
						return temp2;
					}
					temp = temp->getTop();
				}
				elem = temp;
				return temp2;
			}
		}	
		template<typename S,typename K,typename M,typename F>	
		bidirectional_iterator &operator=(const bidirectional_iterator<S,K,M,F> cpy)
		{
			elem = const_cast<pointer>(cpy.getElem());
			return *this;
		}
		reference operator=(const reference cpy)
		{
			elem = cpy.elem;
		}

		bool operator!=(bidirectional_iterator const & cpy) const
		{
			return !(*this == cpy);
		}
		pointer getAddr(void) 
		{
			return elem;
		}
		fpair& operator*(void) 
		{
			return *(elem->getPair()) ;
		}
		fpair& operator*(void) const
		{
			return *(elem->getPair() );
		}
		fpair *operator->(void)
		{
			return elem->getPair();
		}
		const pointer getElem()	const 
		{
			return elem;
		}
		template <typename S,typename A, typename Q,typename B>
			friend bool operator==(bidirectional_iterator<S,Key,mapped,A> const &x,bidirectional_iterator<Q,Key,mapped,B> const& y) 
			{
				if (x.elem == y.elem && x.end == y.end)
					return 1;
				else
					return 0;
			}
		bool operator!=(bidirectional_iterator<T,Key,mapped,fpair> & x)
		{
			return !(*this==x);
		}
	};
	template <  typename  T,class Key,class mapped,class fpair,class Compare = std::less< Key> > 
		class rev_bidirectional_iterator :   iterator_traits<iterator<rev_bidirectional_iterator_tag, T> >
	{
		public :
		typedef typename iterator<rev_bidirectional_iterator_tag,T>::pointer pointer;
		typedef typename iterator<rev_bidirectional_iterator_tag,T>::reference reference;
		typedef typename iterator<rev_bidirectional_iterator_tag,T >::value_type value_type;
		typedef  bidirectional_iterator<T,Key,mapped,fpair> iterator;
		private:
		pointer elem;
		iterator it;
		bool end;
		public :
		bool getEnd()
		{
			return end;
		}
		rev_bidirectional_iterator(void)
		{
			elem =0;
			end = 0;
			it  = 0;
		}
		rev_bidirectional_iterator(const rev_bidirectional_iterator &cpy)
		{
			it = cpy.it;
			elem = cpy.elem;
			end = cpy.end;
		}
		rev_bidirectional_iterator(pointer point, bool e = 0)
		{
			it = iterator(point);
			elem = point;
			end =e; 
		}

		rev_bidirectional_iterator  operator++(int)
		{
			// std::cout<<"dans rev operator ++ int\n";
			rev_bidirectional_iterator temp = *this;
			pointer t_elem = it.getAddr();
			while (t_elem->getTop()!= 0)
				t_elem = t_elem->getTop();
			if (it == t_elem->cbegin())
				end =1;
			else
				it--;
			return temp;
			// pointer temp2=elem;
			// pointer temp = elem;
			// // std::cout<<"rev bidi 1 = "<<elem->getKey()<<" et end = "<<end<<"\n";
			// while (temp->getTop() != 0)
			// {
//
				// // std::cout<<"temp while 1="<<temp->getKey()<<"\n";
				// temp = temp->getTop();
			// }
			// while (temp->getLeft() != 0)
			// {
//
				// // std::cout<<"temp while 2="<<temp->getKey()<<"\n";
				// temp = temp->getLeft();
			// }
//
			// // std::cout<<"rev bidi 2="<<temp->getKey()<<"\n";
			// if (temp->getKey() == elem->getKey())
			// {
//
				// // std::cout<<"rev bidi 2\n";
				// end =1;
				// return  temp2;
			// }
			// if (elem->getLeft() != NULL)
			// {
//
				// // std::cout<<"rev bidi 3\n";
				// elem = elem->getLeft();
				// while (elem->getRight() != NULL)
				// {
					// elem = elem->getRight();
				// }
				// return temp2;
			// }
			// else
			// {
//
				// // std::cout<<"rev bidi 5="<<(elem->getKey())<<"et end = "<<end<<"\n";
				// if (elem->getTop() == 0)
					// return temp2;
				// while (!(Compare()((elem->getTop())->getKey() , elem->getKey())))
				// {
					// // std::cout<<"rev bidi 5\n";
					// elem = elem->getTop();
				// }
				// return temp2;
			// }
		}

		// rev_bidirectional_iterator  operator++(int)
		// {
			// pointer temp = elem;
			// if (elem->getLeft() != NULL)
			// {
				// elem = elem->getLeft();
				// while (elem->getRight() != NULL)
				// {
					// elem = elem->getRight();
				// }
				// return temp;
			// }
			// else
			// {
				// // while (   (elem->getTop())->getKey() > elem->getKey())
				// elem = elem->getTop();
				// while (!(Compare() ((elem->getTop())->getKey() , elem->getKey())))
				// {
					// elem = elem->getTop();
				// }
				// return temp;
			// }
		// }
		// rev_bidirectional_iterator  &operator--(void)
		// {
			// // std::cout<<"++ void\n";
			// pointer temp=elem;
			// if (temp->getRight() != NULL)
			// {
//
				// // std::cout<<"++ void right != NULL"<<elem->getKey()<<"\n";
				// temp = temp->getRight();
//
				// // std::cout<<"++ void right != NULL"<<temp->getKey()<<"\n";
				// while (temp->getLeft() != NULL)
				// {
//
					// // std::cout<<"++ void right != NULL While\n";
					// temp = temp->getLeft();
				// }
				// elem = temp;
				// return *this;
			// }
			// else
			// {
				// if (temp->getTop() == 0)
				// {
//
					// elem = temp;
					// return *this;
				// }
				// while (Compare()((temp->getTop())->getKey() , temp->getKey()))
				// {
//
					// // std::cout<<"++ void right == NULL"<<temp->getKey()<<"\n";
					// temp = temp->getTop();
					// if (temp->getTop() == 0)
					// {
//
						// //elem = temp;
						// return *this;
					// }
				// }
				// elem = temp;
				// return *this;
			// }
		// }
		rev_bidirectional_iterator  &operator++(void)
		{

			// std::cout<<*it<<"debut dans rev operator ++ void\n";
			pointer t_elem = it.getAddr();
			while (t_elem->getTop()!= 0)
			{

			// std::cout<<"dans rev operator ++ void2\n";
				t_elem = t_elem->getTop();
			}
			if (it == t_elem->cbegin())
			{

			// std::cout<<"dans rev operator ++ void3\n";
				end =1;
			}
			else
			{	

			// std::cout<<" beifor it--\n";
				it--;

			// std::cout<<*it<<"dans rev operator ++ void4\n";
			}
				return *this;
			// pointer temp = elem;
			// // std::cout<<"rev bidi 1 = "<<elem->getKey()<<" et end = "<<end<<"\n";
			// while (temp->getTop() != 0)
			// {
//
				// // std::cout<<"temp while 1="<<temp->getKey()<<"\n";
				// temp = temp->getTop();
			// }
			// while (temp->getLeft() != 0)
			// {
//
				// // std::cout<<"temp while 2="<<temp->getKey()<<"\n";
				// temp = temp->getLeft();
			// }
//
			// // std::cout<<"rev bidi 2="<<temp->getKey()<<"\n";
			// if (temp->getKey() == elem->getKey())
			// {
//
				// // std::cout<<"rev bidi 2\n";
				// end =1;
				// return *this;
			// }
			// if (elem->getLeft() != NULL)
			// {
//
				// // std::cout<<"rev bidi 3\n";
				// elem = elem->getLeft();
				// while (elem->getRight() != NULL)
				// {
					// elem = elem->getRight();
				// }
				// return *this;
			// }
			// else
			// {
//
				// // std::cout<<"rev bidi 4"<<(elem->getTop())->getKey()<<" et " <<elem->getKey()<<"\n";
//
				// elem = elem->getTop();
//
				// // std::cout<<"rev bidi 5="<<(elem->getKey())<<"et end = "<<end<<"\n";
				// if (elem->getTop() == 0)
					// return *this;
				// while (!(Compare()((elem->getTop())->getKey() , elem->getKey())))
				// {
					// // std::cout<<"rev bidi 5\n";
					// elem = elem->getTop();
				// }
				// return *this;
			// }
//
//
			// return *this;
		}

		rev_bidirectional_iterator  operator--(int)
		{
	

			rev_bidirectional_iterator temp = *this;
			it++;
			return temp;
			// // std::cout<<"rev_bidirectoal ++ int\n";
			// pointer temp = elem;
			// pointer temp2 = elem;
			// pointer temp_top = elem;
			// while (temp_top->top != 0)
			// {
				// temp_top = temp_top->top;
			// }
			// if (temp_top== elem)
			// {
				// end =1;
				// return temp;
			// }
			// if (temp2->getRight() != NULL)
			// {
//
				// // std::cout<<"rev_bidirectoal ++ int  right != 0\n";
				// temp2 = temp2->getRight();
				// while (temp2->getLeft() != NULL)
				// {
					// temp2 = temp2->getLeft();
				// }
				// elem = temp2;
				// return temp;
			// }
			// else
			// {
				// if (temp->getTop() == 0)
				// {
//
					// return temp2;
				// }
				// while (Compare()((temp->getTop())->getKey() , temp->getKey()))
				// {
//
					// // std::cout<<"++ void right == NULL"<<temp->getKey()<<"\n";
					// temp = temp->getTop();
					// if (temp->getTop() == 0)
					// {
//
						// elem = temp;
						// return temp2;
					// }
				// }
				// elem = temp;
				// return temp2;
			// }

		}	
		reference operator=(const reference cpy)
		{
			it = cpy.it;
			// elem = cpy.elem;
		}

		bool operator!=(rev_bidirectional_iterator const & cpy) const
		{
			return !(*this == cpy);
		}
		pointer getAddr(void) 
		{
			return it.elem;
		}
		fpair& operator*(void) 
		{
			// return *(elem->getPair()) ;

			return *it ;
		}
		fpair& operator*(void) const
		{
			// return *(elem->getPair() );

			return *it ;
		}
		fpair *operator->(void)
		{
			return it->getPair();
			// return elem->getPair();
		}

		template <typename S,typename A, typename Q,typename B>
			friend bool operator==(rev_bidirectional_iterator<S,Key,mapped,A> const &x,rev_bidirectional_iterator<Q,Key,mapped,B> const& y) 
			{
				// std::cout<<"ici x= "<<x.elem->getKey()<<"end = "<<x.end<<" ici y ="<<y.elem->getKey()<<"end="<<y.end<<std::endl;
				return (x.it == y.it && x.end == y.end);

				// if (x.elem == y.elem && x.end == y.end)
					// return 1;
				// else
					// return 0;
			}
		bool operator!=(rev_bidirectional_iterator<T,Key,mapped,fpair> & x)
		{
			return !(*this==x);
		}
		iterator base() const
			{
				return it;
			}
	};
}
#endif
