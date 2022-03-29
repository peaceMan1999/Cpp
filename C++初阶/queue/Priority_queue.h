#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

namespace yz
{
	//�º���
	template <class T>
	struct greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};

	template <class T>
	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};

	template<class T, class Container = vector<T>, class Compare = less<T>>  // ����--less
	//template<class T, class Container = vector<T>, class Compare = greater<T>>  // ����--greater��Ĭ�ϣ�
	class Priotity_queue
	{
	public:

		void AdjustUp(int child)
		{
			size_t parent = (child - 1) / 2;
			Compare com;

			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					::swap(_con[parent], _con[child]);

					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		//���½���
		void AdjustDown(int parent)
		{
			size_t child = parent * 2 + 1;
			Compare com;

			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child+1]))
				{
					child++;
				}
				if (com(_con[parent], _con[child]))
				{
					::swap(_con[parent], _con[child]);
					
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}

		}

		void push(const T& val)
		{
			_con.push_back(val);

			AdjustUp(_con.size() - 1);//������
		}

		void pop()
		{
			::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			//���½��ѣ���Ϊ���Ҷѱ������Ѿ��Ǵ�С���ˣ�����ֱ�����½���
			AdjustDown(0);
		}

		T top()
		{
			return _con[0];
		}

		size_t size()
		{
			_con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};


}
