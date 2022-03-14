#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//string s1;
	//cout << "s1.size():" << s1.size() << endl;
	//cout << "s1.capacity():" << s1.capacity() << endl;
	//cout << endl;

	//s1.resize(20, 'x');
	//cout << "s1.size():" << s1.size() << endl;
	//cout << "s1.capacity():" << s1.capacity() << endl;
	//cout << s1 << endl;
	//cout << endl;

	//string s2 = "hello";
	//s2.resize(20, 'x');
	//cout << "s2.size():" << s1.size() << endl;
	//cout << "s2.capacity():" << s1.capacity() << endl;
	//cout << s2 << endl;

	//string s3;
	////s3.reserve(127);
	//int oldcount = s3.capacity();
	//for (char ch = 0; ch < 127; ch++)
	//{
	//	s3 += ch;
	//	if (oldcount != s3.capacity())
	//	{
	//		cout << "增容：" << oldcount << "->" << s3.capacity() << endl;
	//		oldcount = s3.capacity();
	//	}
	//}

	//string s4 = "hello!!!";
	//s4.resize(20);
	//s4 += "!!!";
	//cout << s4 << endl;

	//cout << strlen(s4.c_str()) << endl;
	//cout << s4.c_str() << endl;
	//cout << s4.size() << endl;

	//要求取出后缀和前缀
	//string filename = "test.cpp";
	//size_t pos = filename.find('.');
	//if (pos != string::npos)
	//{
	//	//string copy(filename, pos, filename.size() - pos);
	//	//string copy(filename);
	//	//string copy = filename.substr(pos);
	//	string copy = filename.substr(pos, filename.size() - pos);

	//	cout << copy << endl;
	//}
	string url1 = "https://blog.csdn.net/m0_64645696?spm=1000.2115.3001.5343";
	//协议
	size_t pos = url1.find("://");
	if (pos != string::npos)
	{
		string copy = url1.substr(0, pos);
		cout << copy << endl;
	}
	else
	{
		string();
	}
	//域名
	size_t start = pos + 3;
	size_t end = url1.rfind('/');
	if (end != string::npos)
	{
		string copy2 = url1.substr(start, end - start);
		cout << copy2 << endl;
	}
	else
	{
		string();
	}

	return 0;
}
