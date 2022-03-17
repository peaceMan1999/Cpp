#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <iostream>
#include <list>
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

	template <class T>
	//封装节点
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T> self;//我自己

		node* _pnode;

		_list_iterator(node* pnode)
			:_pnode(pnode)
		{}
		
		const T& operator*()
		{
			return _pnode->_val;
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
		typedef _list_iterator<T> iterator;
		typedef _list_iterator<T> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator begin() const
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		iterator end() const
		{
			return iterator(_head);
		}

		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& val)
		{
			node* newnode = new node(val);
			node* tail = _head->_prev;
			
			tail->_next = newnode;
			newnode->_prev = tail;
			_head->_prev = newnode;
			newnode->_next = _head;
		}

	private:
		node* _head;

	};

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

	void f1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);

		print(lt);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		//for (auto e : lt)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;
	}

}

