#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <assert.h>
using namespace std;


namespace yz
{
	template <class T>
	//节点
	struct _list_node
	{
		T _val;
		_list_node<T>* _next;
		_list_node<T>* _prev;

		_list_node(const T& val = T())
			:_val(val)
			,_next(nullptr)
			,_prev(nullptr)
		{}

	};

	template <class T, class T1, class T2>
	//封装节点
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, T1, T2> self;//我自己

		node* _pnode;

		_list_iterator(node* pnode)
			:_pnode(pnode)
		{}
		
		T1 operator*()
		{
			return _pnode->_val;
		}

		//it->_pnode->val
		T2 operator->()
		{
			return &_pnode->_val;
		}

		bool operator!=(const self& pself)
		{
			return _pnode != pself._pnode;
		}

		bool operator==(const self& pself)
		{
			return _pnode == pself._pnode;
		}

		self& operator++()
		{
			_pnode = _pnode->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;
		}

		self& operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}
	};

	template <class T>
	//链表
	class list
	{
	public:
		typedef _list_node<T> node;
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list(const list<T>& lt)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}

		list<T>& operator=(list<T> copy)
		{
			swap(_head, copy._head);
			return *this;
		}

		void push_back(const T& val)
		{
			insert(end(), val);
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_back()
		{
			erase(end()._pnode->_prev);
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& val)
		{
			assert(pos._pnode);

			node* cur = pos._pnode;
			node* prev = cur->_prev;
			//prev newnode cur
			node* newnode = new node(val);

			prev->_next = newnode;
			newnode->_prev = prev;
			cur->_prev = newnode;
			newnode->_next = cur;
		}

		iterator erase(iterator pos)
		{
			assert(pos._pnode);
			assert(pos._pnode != _head);

			node* prev = pos._pnode->_prev;
			node* next = pos._pnode->_next;
			prev->_next = next;
			next->_prev = prev;
			delete pos._pnode;

			return iterator(next);
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		bool empty()
		{
			return begin() == end();
		}

		size_t size()
		{
			size_t sz = 0;
			iterator it = begin();
			while (it != end())
			{
				it++;
				sz++;
			}
			return sz;
		}

	private:
		node* _head;

	};

	class date
	{
	public:

		int _year = 0;
		int _mon = 1;
		int _day = 1;
	};

	void d1()
	{
		list<date> d1;
		d1.push_back(date());
		d1.push_back(date());
		d1.push_back(date());

		list<date>::iterator it = d1.begin();
		while (it != d1.end())
		{
			cout << it->_year << " " << it->_mon << " " << it->_day;
			it++;
		}
		cout << endl;
	}

	void print(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it += 1;
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	void f2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		print(lt);


		//lt.clear();
		//print(lt);
		//if (lt.empty())
		//{
		//	cout << "empty " << lt.size() << endl;
		//}
		//list<int> lt2(lt);
		//print(lt2);

		list<int> lt3;
		lt3 = lt;
		print(lt3);

	}

	void f1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_front(4);
		lt.push_front(5);
		print(lt);
		lt.pop_back();
		lt.pop_back();

		print(lt);
		//list<int>::iterator pos = find(lt.begin(), lt.end(), 2);
		//lt.insert(lt.end(), 10);
		//lt.insert(lt.begin(), 20);
		if (!lt.empty())
		{
			cout << "not empty" << lt.size() << endl;
		}
		//list<int>::iterator it = lt.begin();
		//while (it != lt.end())
		//{
		//	cout << *it << " ";
		//	++it;
		//}
		//cout << endl;

		//for (auto e : lt)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;
	}

}

