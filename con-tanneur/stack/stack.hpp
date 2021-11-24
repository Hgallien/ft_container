#include <memory>
#include "Iterator.hpp"
#include "vector.hpp"
#include <iostream>
#include <iterator>

template<typename T, class Container = vector<T> >
class stack
{

	private:
		Container s;
	public:
		typedef Container                                container_type;
		typedef typename container_type::value_type      value_type;
		typedef typename container_type::reference       reference;
		typedef typename container_type::const_reference const_reference;
		typedef typename container_type::size_type       size_type;
		explicit stack (const container_type& ctnr = container_type())
		{
			// std::cout<<"dans construct \n";
			s = ctnr;
			// std::cout<<"dans construct end\n";
		}
		 ~stack()
		 {};

		
		bool empty() const
		{
			return s.empty();
		}
		size_type size() const
		{
			return s.size();
		}
		value_type& top()
		{
			return *((s.end()) - 1);
		}
		const value_type& top() const
		{
			return *((s.end()) - 1);
		}
		void push (const value_type& val)
		{
			s.push_back(val);
		}
		void pop()
		{
			s.pop_back();
		}
		friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return lhs.s==rhs.s;
		}
		friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{

			return lhs.s!=rhs.s;
		}
		friend  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{

			return lhs.s<rhs.s;
		}
		friend  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{

			return lhs.s<=rhs.s;
		}
		friend  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{

			return lhs.s>rhs.s;
		}
		friend  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{

			return lhs.s>=rhs.s;
		}

};
