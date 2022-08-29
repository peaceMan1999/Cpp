/*

输入一行字符串，可以有空格

输出描述：
输出参数个数，分解后的参数，每个参数都独占一行

示例1
输入：
xcopy /s c:\\ d:\\e

输出：
4
xcopy
/s
c:\\
d:\\e

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    vector<string> vv;
    bool flag = false;
    string sub;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '"' && !flag)
        {
            flag = true;
        }
        else if (str[i] == '"')
        {
            flag = false;
        }
        else if (str[i] == ' ')
        {
            if (flag) {
                sub += str[i];
            }
            else {
                vv.push_back(sub);
                sub.clear();
            }
        }
        else
        {
            sub += str[i];
        }
    }
    vv.push_back(sub);

    cout << vv.size() << endl;
    for (int i = 0; i < vv.size(); i++)
    {
        cout << vv[i].c_str() << endl;
    }

    return 0;
}
