#ifndef MAP_HPP
#define MAP_HPP
#include <functional>
#include <cmath>
#include "Iterator.hpp"
#include <queue>
#include <algorithm>
#include "utils.hpp"
template <class Key, class T, class Allocator, class Compare = std::less<Key> >
class node
{

	typedef typename ft::bidirectional_iterator<node<Key, T, Allocator>,Key,T,pair<Key,T> >		iterator;
	typedef	typename Allocator::template	rebind<node>::other n_Allocator;
	typedef typename ft::bidirectional_iterator< node<Key, T, Allocator> const,Key,T,const pair<Key,T> >		const_iterator;
	typedef typename ft::rev_bidirectional_iterator<node<const Key, T, Allocator>,const Key,T,pair<Key,T> >		reverse_iterator;
	typedef typename ft::rev_bidirectional_iterator< const node<const Key, T, Allocator> ,const Key,T,const pair<Key,T>  >		const_reverse_iterator;
	private :
	node *top;
	node *left;
	node *right;
	n_Allocator _alloc;
	Allocator	p_alloc;
	pair< Key, T> *p;
	int	s_right;
	int s_left;
	int size;
	public :
	~node()
	{

	}
	node(node const* cpy)
	{
		// std::cout<<" node const 8cpy\n";
		left=cpy->left;
		right=cpy->right;
		top=cpy->top;
		p = p_alloc.allocate(1);
		p_alloc.construct(p,cpy->p);
	}
	node(node const& cpy)
	{

		// std::cout<<" node const &cpy\n";
		left=cpy.left;
		right=cpy.right;
		top=cpy.top;
		p = p_alloc.allocate(1);
		p_alloc.construct(p,*(cpy.p));
	}
	node(pair< Key,T> const cpy, node * t = 0) 
	{

		// std::cout<<" pair const &cpy node *\n";
		p = p_alloc.allocate(1);
		p_alloc.construct(p,cpy);
		// *p = pair<const Key, T>(cpy);
		top=t;
		left = 0;
		right = 0;
		s_left = 0;
		s_right =0;
		size = 0;
	}
	node(Key  cpy, node *t = 0)
	{

		// std::cout<<" key cpy   node *t\n";
		p = p_alloc.allocate(1);
		p_alloc.construct(p,pair<const Key,T>(cpy));
		top=t;
		left = 0;
		right = 0;
		s_right = 0;
		s_left = 0;
		size = 0;
	}
	void rec(node const *n)
	{
		// std::cout<<"dans rec\n";
		if (n->left != 0)
		{
			left=_alloc.allocate(1);
			_alloc.construct(left,*(n->left));
			left->top = this	;
			left->left = 0;
			left->right = 0;
			left->rec(n->left);	
			s_left = n->left->s_left+1;
		}
		else
		{
			left = 0;
			s_left = 0;
		}
		if (n->right != 0)
		{
			right=_alloc.allocate(1);
			_alloc.construct(right,*(n->right));
			right->top = this	;
			right->right = 0;
			right->left = 0;
			right->rec(n->right);
			s_right = n->right->s_right+1;
		}
		else
		{
			right = 0;
			s_right = 0;
		}
	}

	pair<const Key, T> *getPair()
	{
		return p;	
	}
	pair<const Key, T> *getPair() const
	{
		return p;	
	}
	node *getRight(void) const
	{
		return right;
	}
	node *getLeft(void) const
	{
		return left;
	}
	int	getSleft()
	{
		return s_left;
	}
	int	getSright()
	{
		return s_right;
	}
	node *getTop(void) const
	{
		return top;
	}
	Key getKey() const
	{
		return p->getF();
	}
	T &getContent() const
	{
		return (p->second);
	}
	void	set_size(const Key k)
	{
		if (k == p->getF())
		{
			return;
		}
		if (Compare()(k, p->getF()))
		{ 
			if(left==0)
				return ;
			else 
			{
				s_left--;
				left->set_size(k);
			}
		}
		else
		{
			if(right==0)
				return ;
			else {
				s_right--;
				right->set_size(k);
			}
		}
	}
	node *find(const Key k)
	{
		if (k == p->getF())
		{
			return this;
		}
		if (Compare()(k, p->getF()))
		{ 
			if(left==0)
				return 0;
			else 
				return left->find(k);
		}
		else
		{
			if(right==0)
				return 0;
			else 
				return right->find(k);
		}

	}
	bool heavy_right(void)
	{

		if (s_right - 1 > s_left)
		{
			return true;
		}
		return false;
	}
	bool heavy_left(void)
	{
		if (s_left - 1 > s_right)
		{
			return true;
		}
		return false;
	}
	void	find_balance(void)
	{
		if (heavy_right())
		{
			if (right->heavy_right() || right->heavy_left())
				right->find_balance();
			else
				left_rotation();
		}
		else if (heavy_left())
		{
			if (left->heavy_right() || left->heavy_left())
				left->find_balance();
			else
				right_rotation();
		}
	}
	void	find_erase_balance(Key const k)
	{

		if (Compare()(getKey(),k))
		{
			right->find_erase_balance(k);

		}
	}
	void	balance(void)
	{

		std::cout<<"key = "<<getKey()<<"before penis s_left = "<< s_left <<"s_ritght ="<<s_right<<"\n";
		if (s_right - 1 > s_left)
		{
			std::cout<<"penis one "<<getKey()<<"\n";
			left_rotation();
			//std::cout<<"top ="<<top->getKey()<<std::endl	;
			// //std::cout<<"penis s_left = "<< s_left <<"s_ritght ="<<s_right<<"\n";
			//
			// std::cout<<"top penis s_left = "<< top->s_left <<"s_ritght ="<<top->s_right<<"\n";
		}
		else if (s_left - 1 > s_right)
		{

			std::cout<<"penis two"<<getKey()<<"\n";
			right_rotation();
		}
	}
	pair<node*,bool>	insert(Key const k)
	{
		// std::cout<<"tohet insert\n";
		pair<node*,bool> temp;
		if (k == p->getF())
			return pair<node*,bool>(this,0);
		if (Compare()(k, p->getF()))
		{
			if (left == 0)
			{

				left = _alloc.allocate(1);
				_alloc.construct(left,pair<const Key,T>(k),this);
				s_left++;
				return pair<node*,bool>(left,1);
			}
			else
			{
				temp = left->insert(k);
				s_left = left->s_left +temp.second;
				size =  std::max(s_left,s_right);
				balance();
				// return left->insert(k);
				return temp;
			}
		}
		else
		{
			if (right == 0)
			{
				right = _alloc.allocate(1);
				_alloc.construct(right,pair<const Key,T>(k),this);
				s_right++;
				return pair<node*,bool>(right,1);
			}
			else
			{
				temp = right->insert(k);
				s_right = right->s_right +temp.second;
				size =  std::max(s_left,s_right);
				balance();
				return temp;
				// return right->insert(k);
			}
		}
	}
	pair<node*,bool>	insert(pair<const Key,T>   i)
	{

		pair<node*,bool> temp;
		// std::cout<<"dans indert node "<<i.getF()<<" " <<p->getF()<<"\n";
		if (i.getF() == p->getF())
			return pair<node*,bool>(this,0);
		// std::cout<<"dans indert node0.5\n";
		if (Compare()(i.getF(), p->getF()))
		{
			// std::cout<<"dans indsert pair, i < f \n";
			if (left == 0)
			{

				// std::cout<<"dans indsert pair, i < f left == 0 \n";
				left = _alloc.allocate(1);
				_alloc.construct(left,i,this);
				s_left++;
				return pair<node*,bool>(left,1);
			}
			else{

				temp = left->insert(i);
				s_left = left->s_left +temp.second;
				size =  std::max(s_left,s_right);
				balance();
				return temp;
			}
			// return left->insert(i);
		}
		else
		{

			// std::cout<<"dans indert node2\n";
			if (right == 0)
			{
				right = _alloc.allocate(1);
				_alloc.construct(right,i,this);
				s_right++;
				// right = new node(i,this);
				return pair<node*,bool>(right,1);
			}
			else
			{
				temp = right->insert(i);
				// std::cout<<"dans inser key = "<<getKey()<<" s_right = "<<s_right"
				s_right = right->s_right +temp.second;
				size =  std::max(s_left,s_right);
				balance();
				return temp;
			}
			// return right->insert(i);
		}
	}
	bool	operator==(node* cmp)
	{
		if (this == cmp)
			return 1;
		else
			return 0;
	}
	int height(void)
	{

		// std::cout<<"dans height "<<getKey()<<std::endl;
		if (left == 0 && right == 0)
			return 1;
		else if (right == 0)
			return 1 + left->height();
		else if (left == 0)
			return 1 + right->height();
		else
			return 1 + std::max(left->height(),right->height());
	}
	const_iterator cbegin() const
	{
		if (left != 0)
			return left->cbegin();
		else
			return const_iterator(this);
	}
	const_iterator cend() const
	{
		if(right !=0)
			return right->cend();
		else
			return const_iterator(this,1);
	}
	reverse_iterator rbegin()
	{

		if (right != 0)
			return right->rbegin();
		else
			return reverse_iterator(this);
	}
	const_reverse_iterator crbegin()
	{

		if (right != 0)
			return right->crbegin();
		else
			return const_reverse_iterator(this);
	}
	iterator begin()
	{

		if (left != 0)
			return left->begin();
		else
			return iterator(this);
	}
	reverse_iterator rend()
	{
		if(left !=0)
			return left->rend();
		else
			return reverse_iterator(this,1);
	}
	const_reverse_iterator crend()
	{
		if(left !=0)
			return left->crend();
		else
			return const_reverse_iterator(this,1);
	}
	iterator end()
	{
		if(right !=0)
			return right->end();
		else
			return iterator(this,1);
	}

	void	erase_bis(node * temp,node **head)
	{
		if (top!= 0)
		{
			if(Compare()(top->getKey(),getKey()))
			{
				top->right = temp;

				top->s_right = top->s_right -1;
			}
			else
			{
				top->left = temp; 
				top->s_left = top->s_left -1;
			}
			temp->top = top;
		}
		else
		{
			temp->top = 0;
			*head = temp;
		}
		temp->right = right;

		if (right)
			right->top = temp;
		// std::cout<<"ici p ="<<p->first<<" "<<p->second<<std::endl;
		p_alloc.destroy(p);
		p_alloc.deallocate(p,1);
		_alloc.destroy(this);
		_alloc.deallocate(this,1);
	}

	void erase_setSize(node * end)
	{
		if(getKey() == end->getKey())
		{
			s_left = std::max(left->s_left,right->s_right);
			return;
		}
		if (right == 0)
			s_right = 0;
		else
		{
			s_right = std::max(right->s_left,right->s_right) ;
		}
		top->erase_setSize(end);
	}
	node*	erase(node **head)
	{
		node * to_return = top;
		if(left== 0 &&right == 0)
		{
			//std::cout<<" erase left == 0 right == 0\n";
			if(top !=0)
			{
				if (Compare()(top->getKey(),getKey()))
				{
					top->right = 0;
					top->s_right = 0;
				}
				else
				{
					top->left = 0;
					top->s_left = 0;
				}
			}
			else
			{
				*head = 0;
			}
			p_alloc.destroy(p);
			p_alloc.deallocate(p,1);
			_alloc.destroy(this);
			_alloc.deallocate(this,1);
			return top;
		}
		else if(left==0)
		{
			//std::cout<<"   left == 0\n";
			if ( top != 0)
			{

				//std::cout<<"   left == 0 top != 0\n";
				if(Compare()(top->getKey(),getKey()))
				{

					//std::cout<<" if  top key<<="<<top->getKey()<<"key = "<<getKey()<<std::endl;
					top->right = right;

					top->s_right = top->s_right - 1;
					right->top = top;
				}
				else
				{

					//std::cout<<" else  top key<<="<<top->getKey()<<"key = "<<getKey()<<std::endl;
					top->left = right; 
					top->s_left = top->s_left - 1;
					right->top = top; 

					//std::cout<<"end\n"; 
				}
			}
			else
			{
				//std::cout<<" erase left == 0 top == 0\n";
				right->top = 0;
				*head = right;

			}
			p_alloc.destroy(p);
			p_alloc.deallocate(p,1);
			_alloc.destroy(this);
			_alloc.deallocate(this,1);

			//std::cout<<"end2\n"; 
			return to_return;
		}
		else if (right == 0)
		{

			// std::cout<<"   right == 0\n";
			if ( top != 0)
			{
				if(Compare()(top->getKey(),getKey()))
				{
					top->right = left;
					left->top = top;
					top->s_right = top->s_right - 1;
				}
				else
				{
					top->left = left; 
					left->top = top;
					top->s_left = top->s_left - 1;
				}
			}
			else
			{
				left->top = 0;
				*head = left;
			}
			p_alloc.destroy(p);
			p_alloc.deallocate(p,1);
			_alloc.destroy(this);
			_alloc.deallocate(this,1);
			return to_return;
		}
		else
		{
			std::cout<<"ici\n";
			node * temp;
			temp = left;
			if( temp->right == 0)
			{
				erase_bis(temp,head);
				return temp;
			}
			while (temp->right !=0)
				temp=temp->right;
			temp->top->s_right = temp->top->s_right - 1;
			temp->top->top->erase_setSize(this);
			std::cout<<"noeud pleins, temp key = "<<temp->getKey()<<std::endl;
			// std::cout<<"noeud pleins, head key = "<<(*head)->getKey()<<std::endl;
			if (top!= 0)
			{

			std::cout<<"noeud pleins, top key = "<<top->getKey()<<std::endl;
				if(Compare()(top->getKey(),getKey()))
				{
					top->right = temp;

					top->s_right = top->s_right - 1;
				}
				else
				{
					top->left = temp; 

					top->s_left = top->s_left - 1;
				}
				if(temp->left!=0)
				{
					temp->top->right = temp->left;

			
					temp->left->top =temp->top; 

			std::cout<<"noeud pleins,  temp left  = "<<temp->left->getKey()<<std::endl;
			std::cout<<"noeud pleins,  temp left top = "<<temp->left->top->getKey()<<std::endl;
			std::cout<<"noeud pleins,  temp  top = "<<temp->top->getKey()<<std::endl;
				}
				else
				{
					temp->top->right = 0;
				}
				temp->left = left;
				temp->right = right;
				temp->top = top;
				temp->s_right = s_right;
				temp->s_left = s_left;
				p_alloc.destroy(p);
				p_alloc.deallocate(p,1);
				_alloc.destroy(this);
				_alloc.deallocate(this,1);
				return temp;
			}
			else
			{
				// node * temp_bis;
				// std::cout<<"erase noeud pleins top ==0 \n ";
				if(temp->left!=0)
				{

					// std::cout<<"erase noeud pleins top ==0  temp->left != 0\n ";
					if(Compare()(temp->top->getKey(),temp->getKey()))
					{
						temp->top->right = temp->left;
						temp->left->top = temp->top;
					}
					else
					{
						temp->top->left = temp->left; 
						temp->left->top = temp->top;
					}
					// std::cout<<"erase noeud pleins top ==0 left!=0\n ";
				}
				else
				{

					// std::cout<<"erase noeud pleins top ==0  temp->left == 0\n ";
					if(Compare()(temp->top->getKey(),temp->getKey()))
					{

						// std::cout<<"erase noeud pleins top ==0left==0 top <temp\n ";
						temp->top->right = 0;
					}
					else
					{

						// std::cout<<"erase noeud pleins top ==0left==0 top >temp\n ";
						temp->top->left = 0; 

						// std::cout<<"erase noeud pleins top ==0left==0 top >temp after op\n ";
					}
				}

				// std::cout<<"erase noeud pleins top ==0 after0.5\n ";
				temp->left = left;
				// std::cout<<"erase noeud pleins top ==0 after0.75 left = "<<temp->getKey()<<" \n ";
				if (left)
					left->top = temp;
				temp->s_right = s_right;
				// std::cout<<"erase noeud pleins top ==0 after1\n ";
				temp->right = right;
				// std::cout<<"erase noeud pleins top ==0 after2\n ";
				temp->top = top;
				// std::cout<<"erase noeud pleins top ==0 after3\n ";
				*head = temp;

				// std::cout<<"erase noeud pleins top ==0 after3\n ";
				p_alloc.destroy(p);
				// std::cout<<"erase noeud pleins top ==0 after4\n ";
				p_alloc.deallocate(p,1);
				// std::cout<<"erase noeud pleins top ==0 after5\n ";
				_alloc.destroy(this);
				// std::cout<<"erase noeud pleins top ==0 after6\n ";
				_alloc.deallocate(this,1);
				return temp;
			}
			// *p = *(temp->p);
			//
			// // p->first = temp->p->first;
			// // p->second = temp->p->second;
			// p_alloc.destroy(temp->p);
			// std::cout<<"noeud pleins, head key = "<<(*head)->getKey()<<std::endl;
			// p_alloc.deallocate(temp->p,1);
			// std::cout<<"noeud pleins, head key = "<<(*head)->getKey()<<std::endl;
			// _alloc.destroy(temp);
			// std::cout<<"noeud pleins, head key = "<<(*head)->getKey()<<std::endl;
			// _alloc.deallocate(temp,1);
			//
			// std::cout<<"noeud pleins, head key = "<<(*head)->getKey()<<std::endl;
		}
	}
	void clear()
	{
		// Key temp = getKey();
		// std::cout<<"key = "<<temp<<std::endl;
		if(left!=0)
			left->clear();
		if(right!=0)
			right->clear();
		p_alloc.destroy(p);
		// std::cout<<"1 key = "<<temp<<std::endl;
		p_alloc.deallocate(p,1);
		// std::cout<<"2 key = "<<temp<<std::endl;
		_alloc.destroy(this);
		// std::cout<<"3 key = "<<temp<<std::endl;
		_alloc.deallocate(this,1);
		// std::cout<<"4 key = "<<temp<<std::endl;
	}
	void	left_rotation()
	{
		// std::cout<<"start left roration?\n";
		node * temp = right->left;
		s_right = right->s_left;
		size = std::max(s_left,s_right);
		right->s_left = s_left + 1;
		right->size = std::max(right->s_left,right->s_right);
		if ( top == 0)

		{

		// std::cout<<"top = 0\n";
			right->top = top;
		
		}
		else if (Compare()(top->getKey(),getKey()))
		{

			right->top = top;
			top->right = right;
		}
		else
		{

			right->top = top;
			top->left = right;
		}
		top = right;
		right->left = this;
		right = temp;
		if ( temp != 0)
		{
			temp->top = this;
		}
	}
	void	right_rotation()
	{

		// std::cout<<"ici?\n";
		node * temp = left->right;

		s_left = left->s_right;
		size = std::max(s_left,s_right);

		left->s_right = s_right + 1;
		left->size = std::max(left->s_left,left->s_right);
		if ( top == 0)
			left->top = top;
		else if (Compare()(top->getKey(),getKey()))
		{
			left->top = top;
			top->right = left;
		}
		else
		{
			left->top = top;
			top->left = left;
		}
		top = left;
		left->right = this;
		left = temp;
		if(temp!=0)
			temp->top =this;
	}
	void	left_right_rotation()
	{
		left->right->left = left;
		left->right->top = this;
		left->top = left->right;
		left->right = 0;
		right_rotation();
	}
	void	right_left_rotation()
	{
		right->left->right = right;
		right->left->top = this;
		right->top = right->left;
		right->left=0;
		left_rotation();
	}

};

template <class Key, class T, class Compare = std::less<Key>,
		 class Allocator = std::allocator< pair<const Key, T> > >
		 class map
{
	public:
		typedef Key                                      key_type;
		typedef T                                        mapped_type;
		typedef pair<const key_type, mapped_type>        value_type;
		typedef Compare                                  key_compare;
		typedef Allocator                                allocator_type;
		typedef typename allocator_type::reference       reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer         pointer;
		typedef typename allocator_type::const_pointer   const_pointer;
		typedef typename allocator_type::size_type       size_type;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename ft::bidirectional_iterator<node<const Key, T, Allocator>,const Key,T,value_type >		iterator;
		typedef typename ft::bidirectional_iterator< const node<const Key, T, Allocator> ,const Key,T,const value_type >		const_iterator;

		typedef typename ft::rev_bidirectional_iterator<node<const Key, T, Allocator>,const Key,T,value_type >		reverse_iterator;
		typedef typename ft::rev_bidirectional_iterator< const node<const Key, T, Allocator> ,const Key,T,const value_type >		const_reverse_iterator;
		// typedef std::reverse_iterator<iterator>          reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
		// typedef INSERT_RETURN_TYPE<iterator, node_type>  insert_return_type;
		typedef	typename Allocator::template	rebind<node<const Key, T, Allocator> >::other n_Allocator;
	private :
		node< const Key, T, Allocator> *head;
		Allocator _alloc;
		n_Allocator n_alloc;
		key_compare kc;
		unsigned int _size;
	public :
		node<const Key,T,Allocator> *getHead()
		{
			return head;
		}
		class value_compare : Compare
	{
		bool operator()(value_type const &a, value_type const &b)
		{
			return Compare()(a.first,b.first);
		}
	};

		//CONSTRUCTOR & DESTRUCTOR
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			kc = comp;
			head = 0;
			_size = 0;
		}

		// map (iterator first, iterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		template <class InputIterator>
			map(typename enable_if<typename is_same< typename is_integral<InputIterator>::value, std::false_type>::value,InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{

				kc = comp;
				_alloc = alloc;
				_size = 0;
				head = 0;
				// (void)last;
				// while(first->getTop() != NULL)
				// {
				// first++;
				// }
				// head->rec(*first);


				while(first != last)
				{
					std::cout<<*first<<std::endl;

					insert(*first);

					first++;
				}



			}
		map (const map& x)
		{
			const_iterator first = x.begin();
			// std::cout<<"before "<<((first.getAddr())->getTop())->getKey()<<std::endl;
			while(first.getAddr()->getTop() != NULL )
			{

				first++;
				// std::cout<<"first = "<<*first<<"end = "<<*(x.end())<<std::endl;
			}
			head = n_alloc.allocate(1);
			n_alloc.construct(head,*(first.getAddr()));
			// const node<const Key,T,Allocator> *temp;
			// temp = first.getAddr();
			// head->rec(temp);
			head->rec(first.getAddr());
			_size = x._size;

		}
		map& operator= (const map& x)
		{
			if (head != 0)
				clear();
			head = n_alloc.allocate(1);
			n_alloc.construct(head,*(x.head));
			head->rec(x.head);
			_size = x._size;
			return *this;
		}
		~map()
		{
			// std::cout<<"destroy map\n";
			if (head!=0)
				clear();
			// std::cout<<"destroy map end\n";
		}
		//CAPACITY
		bool empty()
		{
			if (head == 0)
				return 1;
			else 
				return 0;
		}
		size_type size() const
		{
			return (_size);
		}
		//MAX SIZE A FAIRE
		//ITERATOR
		reverse_iterator	rbegin()
		{
			if (head == 0)
				return 0;
			return head->rbegin();
		}
		reverse_iterator	rend()
		{
			if (head == 0)
				return 0;
			return head->rend();
		}
		const_reverse_iterator	rbegin() const
		{
			if (head == 0)
				return 0;
			return head->crbegin();
		}
		const_reverse_iterator	rend() const
		{
			if (head == 0)
				return 0;
			return head->crend();
		}
		iterator	begin()
		{
			if (head == 0)
				return 0;
			return head->begin();
		}
		iterator	end()
		{
			if (head == 0)
				return 0;
			return head->end();
		}
		const_iterator	begin() const
		{
			if (head == 0)
				return 0;
			return head->cbegin();
		}
		const_iterator	end()const
		{
			if (head == 0)
				return 0;
			return head->cend();
		}
		//ELEMENT ACCESS
		//
		//MODIFIER
		void swap (map& x)
		{
			node<const Key, T, Allocator> *temp = x.head;
			unsigned int temp_size = x._size;	
			x.head = head;
			x._size = _size;
			head =temp;
			_size=temp_size;
		}
		void clear()
		{
			if (head != 0)
				head->clear();
			head = 0;
			_size =0;
			// std::cout<<"High clear\n";
		}
		void erase (iterator position)
		{
			node<const Key, T, Allocator> *temp;

			 int i = 0;
				for(iterator it = begin();it != end();it++)
				{
					 std::cout<<*it<<"////////\n";
				i++;
					if (i>30)
					break;
				}
			temp = position.getAddr()->erase(&head);
			// std::cout<<"erase position before while "<<(head)->getKey()<<"right,left = "<<(head)->getSright()<<" "<<(head)->getSleft()<<"\n";
			// print_tree();
			while(temp != 0)
			{

			// std::cout<<"la "<<temp->getKey()<<"right,left = "<<temp->getSright()<<" "<<temp->getSleft()<<"\n";
				print_tree();

			  i = 0;
				for(iterator it = begin();it != end();it++)
				{
					 std::cout<<*it<<"\n";
				i++;
					if (i>30)
					break;
				}
				temp->balance();
				while (head->getTop() !=0)
				{

					// std::cout<<"la\n";
					head = head->getTop();
				}
				// std::cout<<"after balance \n";
			// print_tree();
				temp = temp->getTop();
				// std::cout<<"la4 \n";
			}
			_size--;
			if (_size == 0)
				head = 0;
		}
		size_type erase (const key_type& k)
		{
			iterator it = find(k);
			if (it!= end())
			{
				erase(it);
				// head->set_size(k);
				// it.getAddr()->erase(&head);
				// _size--;
				return 1;
			}
			else 
				return 0;
		}
		void erase (iterator first, iterator last)
		{
			iterator temp;
			// std::cout<<"la "<<first->first<<"\n";

			// std::cout<<"la "<<last->first<<"\n";
			while(first!= last )
			{
				temp = first++;	 
				// std::cout<<"laavnt first"<<first->first<<"\n";
				// std::cout<<"apres first"<<first->first<<"\n";
				// std::cout<<"la temp"<<temp->first<<"\n";
				//std::cout<<"la first"<<first->first<<"\n";
				erase(temp);
			}
			// while(first!= last)
			// {
			// // std::cout<<"la "<<first->first<<"\n";
			// // print_tree();
			// head->set_size((*first).first);
			// first.getAddr()->erase(&head);
			// _size--;
			// first++;
			// }
			// print_tree();
		}

		pair<iterator,bool> insert (const value_type& val)
		{

			if (head != 0)
			{
				pair<node<const Key,T, Allocator>*, bool> temp =  head->insert(val);
				if (temp.second == 1)
					_size++;
				// std::cout<<"insert fings\n";
				while (head->getTop() !=0)
					head = head->getTop();
				return pair<iterator,bool>(iterator(temp.getF()),temp.second);
			}
			else
			{
				head = n_alloc.allocate(1);
				n_alloc.construct(head,val);
				_size++;
				return pair<iterator,bool>(iterator(head),1);
			}
		}
		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			pair<iterator,bool> temp= (insert(val));
			// if (temp.second == 1)
			// _size++;
			while (head->getTop() !=0)
				head = head->getTop();
			return temp.getF();
		}
		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last)
		//
		template <class InputIterator>
			void insert(typename enable_if<typename is_same< typename is_integral<InputIterator>::value, std::false_type>::value,InputIterator>::type first, InputIterator last)
			{
				for (;first!= last;first++)
				{
					//std::cout<<"ici\n";
					insert(*first);
					// if (((head->insert(*first)).second == 1))
					// _size++;
				}
				while (head->getTop() !=0)
				{

					//std::cout<<"la\n";
					head = head->getTop();
				}

				//std::cout<<"penis\n";
			}
		mapped_type& operator[] (const key_type& k)
		{

			pair<const Key,T> p_temp(k);
			if(head == 0)
			{

				head =n_alloc.allocate(1);
				n_alloc.construct(head,pair<const Key,T>(k));
				_size++;
				// std::cout<<"[] 4\n";

				return ((head->getPair())->second);
			}
			pair<node< const Key, T,Allocator>*,bool> temp1(head->insert(p_temp));

			if (temp1.second == 1)
				_size++;
			while (head->getTop() !=0)
				head = head->getTop();
			return ((temp1.first)->getPair())->second;	
		}
		//OBERSERVERS
		key_compare key_comp() const
		{
			return kc;
		}
		value_compare value_comp() const
		{
			return value_compare();
		}
		//OPERATION
		iterator find (const key_type& k)
		{
			node<const Key,T,Allocator> *temp =head->find(k);
			if(temp != 0)
				return iterator(temp);
			else
				return head->end();
		}
		const_iterator find (const key_type& k) const
		{
			node<const Key,T,Allocator> *temp =head->find(k);
			if(temp != 0)
				return const_iterator(temp);
			else
				return head->end();
		}
		size_type count (const key_type& k) const
		{
			node<const Key,T,Allocator> *temp =head->find(k);
			if(temp != 0)
				return 1;
			else
				return 0;
		}
		iterator lower_bound (const key_type& k)
		{

			// std::cout<<"lower bound\n";
			iterator it = begin();

			// std::cout<<"lower bound\n";
			for(; it!= end(); it++)
			{
				// std::cout<<"lower bound end = "<<*end()<<"it = "<<*it<< "\n";
				if (!(Compare()(it->first,k)))//|| it->first == k))
				{
					return it;
				}
			}
			return it;
		}

		const_iterator lower_bound (const key_type& k) const
		{
			iterator it = begin();
			for(; it!= end(); it++)
			{
				if (!(Compare()(it->first,k)))//|| it->first == k))
				{
					return const_iterator(it);
				}
			}
			return const_iterator(it);
		}
		iterator upper_bound (const key_type& k)
		{
			iterator it = begin();
			for(; it!= end(); it++)
			{
				if (!(Compare()(it->first,k))&& it->first != k)
				{
					return it;
				}
			}
			return it;
		}
		const_iterator upper_bound (const key_type& k) const
		{

			// std::cout<<"begin upper_bound 0 \n";
			iterator it = begin();

			//std::cout<<"begin upper_bound  \n";
			for(; it!= end(); it++)
			{

				//std::cout<<"in for upper_bound  \n";
				if (!(Compare()(it->first,k)) && it->first != k)
				{
					return const_iterator(it);
				}
			}
			//std::cout<<"end_upper bound  \n";
			return const_iterator(it);
		}
		pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
		{
			node<Key,T,Allocator> *temp;
			temp = head->find(k);
			if(temp == 0)
			{
				return pair<const_iterator, const_iterator>(upper_bound(k),upper_bound(k));
			}
			else
			{
				return pair<const_iterator, const_iterator>(iterator(temp),upper_bound(k));
			}
		}
		pair<iterator,iterator>				equal_range (const key_type& k)
		{
			node<const Key,T,Allocator> *temp;

			// std::cout<<"before find\n";
			temp = head->find(k);
			// if(temp)
			// std::cout<<"after find"<<temp->getKey()<<"\n";
			if(temp == 0)
			{

				// std::cout<<"temp == 0 \n";
				return pair<iterator, iterator>(upper_bound(k),upper_bound(k));
			}
			else
			{

				// std::cout<<"temp != 0 \n";
				return pair<iterator, iterator>(iterator(temp),upper_bound(k));
			}
		}
		//PERSO

		void	print_tree()
		{

			std::cout<<"dans print tree\n";
			int i = 0;
			int tour = 0;
			// std::cout<<"dans print tree1.25"<<head->getKey()<<"\n";
			int space = pow(2,head->height() -1 );

			// std::cout<<"dans print tree1.35\n";
			int vide = 0;
			int v = 1;
			int debug = 0;
			std::queue<node<const Key,T, Allocator>*> n;
			// std::cout<<"dans print tree1.5\n";

			// std::cout<<"dans print tree1.75\n";
			node<const Key,T, Allocator>* temp;

			node<const Key,T, Allocator>* temp_head = head;

			n.push(temp_head);
			node<const Key,T, Allocator>* temp2;
			for (int x = 0 ; x <space ; x++)
			{
				std::cout<<" ";
			}
			while(!n.empty() )//&& debug < 15)
			{

				// std::cout<<"dans print tree2\n";
				debug++;
				temp = n.front();
				n.pop();

				if (temp->getKey() == '*')
					std::cout<<(char)(temp->getKey()); 
				else
					std::cout<<(temp->getKey()); 
				i++;
				if (i != 0 && i == pow(2,tour)/2)
					std::cout<<" ";

				if(i == pow(2,tour))
				{
					if (v == 0)
					{

						std::cout<<"\n";
						return;
					}
					std::cout<<"\n";
					for (int x = 0 ; x <space -pow(2,tour); x++)
					{
						std::cout<<" ";
					}
					tour++;
					i = 0;
					v = 0;
				}
				if (temp->getKey() == '*')
				{
					pair<const char,int> p1('*' , 0);
					temp2 = n_alloc.allocate(1);
					n_alloc.construct(temp2, node<const Key,T,Allocator>(p1));
					n.push(temp2);
					temp2 = n_alloc.allocate(1);
					n_alloc.construct(temp2, node<const Key,T,Allocator>(p1));
					n.push(temp2);
					delete temp;
					continue;
				}
				if(temp->getLeft()!= 0)
				{
					// std::cout<<"dans left ";
					n.push(temp->getLeft());
					if (temp->getKey()!='*')
						v++;
				}
				else
				{
					pair<const char,int> p1('*' , 0);
					temp2 = n_alloc.allocate(1);
					n_alloc.construct(temp2, node<const Key,T,Allocator>(p1));
					n.push(temp2);
				}
				if(temp->getRight()!= 0)
				{
					// std::cout<<"dans right ";
					n.push(temp->getRight());
					if (temp->getKey()!='*')
						v++;
				}
				else
				{
					pair<const char,int> p1('*' , 0);
					temp2 = n_alloc.allocate(1);
					n_alloc.construct(temp2, node<const Key,T,Allocator>(p1));
					n.push(temp2);
					// n.push(node<Key,T,Allocator>("*",0));
					vide ++;
				}
				// std::cout<<"v == "<<v<<" ";
			}
			std::cout<<"\n";
		}
};

#endif
