#define _CRT_SECURE_NO_WARNINGS 1

/*
Webϵͳͨ����Ƶ���ط������ݿ⣬���ÿ�η��ʶ����������ӣ����ܻ�ܲΪ��������ܣ��ܹ�ʦ���������Ѿ����������ӡ����յ����󣬲������ӳ���û��ʣ����õ�����ʱ��ϵͳ�ᴴ��һ�������ӣ������������ʱ�����ӻᱻ�������ӳ��У�����������ʹ�á�

�����ṩ�㴦���������־���������һ�����ӳ������Ҫ�������ٸ����ӡ�
*/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// �� set ��
int main()
{
    int n;
    string id, con;
    while (cin >> n)
    {
        set<string> data;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> id >> con;
            if (con == "connect")
            {
                data.insert(id);
            }
            else
            {
                data.erase(id);
            }
            int num = data.size();
            count = max(num, count);
        }
        cout << count << endl;
    }
    return 0;
}
