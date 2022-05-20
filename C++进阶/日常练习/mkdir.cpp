#define _CRT_SECURE_NO_WARNINGS 1

/*
工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。例如要创建目录“/usr/local/bin”，就需要此次创建“/usr”、“/usr/local”以及“/usr/local/bin”。好在，Linux下mkdir提供了强大的“-p”选项，只要一条命令“mkdir -p /usr/local/bin”就能自动创建需要的上级目录。
现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir -p”命令。

注意 /a/bc/b 和 /a/b/bc
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        string str;
        vector<string> dir(n);
        for (int i = 0; i < n; i++)
        {
            cin >> dir[i];
        }
        // 排序
        sort(dir.begin(), dir.end());
        // 标记数组
        vector<int> index(n, 1);
        for (int i = 0; i < n - 1; i++)
        {
            if (dir[i + 1].find(dir[i]) != string::npos)
            {
                index[i] = 2;
            }
            if (dir[i + 1].size() > dir[i].size() && dir[i + 1][dir[i].size()] != '/')
            {
                index[i] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (index[i] == 1)
            {
                cout << "mkdir -p " << dir[i] << endl;
            }
        }
        cout << endl;
    }
}