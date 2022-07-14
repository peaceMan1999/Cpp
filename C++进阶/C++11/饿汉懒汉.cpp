#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <mutex>

using std::cout;
using std::endl;
//// 饿汉模式
//
//class Singleton{
//public:
//	static Singleton* Create()
//	{
//		return _inst;
//	}
//
//	void Print()
//	{
//		cout << _a << endl;
//	}
//
//private:
//	Singleton()
//	{
//		_a = 0;
//	}
//
//	Singleton(const Singleton&) = delete;
//	Singleton operator = (const Singleton&) = delete;
//
//	int _a;
//
//	static Singleton* _inst;
//};
//
//Singleton* Singleton::_inst = new Singleton;

// 懒汉模式

class Singleton {
public:
	static Singleton* Create()
	{
		// 双检查加锁
		if (_inst == nullptr) {
			_mut.lock();
			if (_inst == nullptr) {
				_inst = new Singleton;
			}
			_mut.unlock();
		}

		return _inst;
	}

	static void DelSingleton()
	{
		// 双检查加锁
		_mut.lock();
		if (_inst != nullptr) {
			delete _inst;
			_inst = nullptr;
		}
		_mut.unlock();
	}

	void Print()
	{
		cout << _a << endl;
	}

private:
	Singleton()
		:_a(0)
	{}

	~Singleton()
	{}

	Singleton(const Singleton&) = delete;
	Singleton operator = (const Singleton&) = delete;

	int _a;
	static std::mutex _mut;

	static Singleton* _inst;
};

Singleton* Singleton::_inst = nullptr;
std::mutex Singleton::_mut;

int main()
{
	cout << Singleton::Create << endl;

	Singleton::Create()->Print();

	return 0;
}