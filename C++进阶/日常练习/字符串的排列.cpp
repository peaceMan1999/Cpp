#define _CRT_SECURE_NO_WARNINGS 1

/*
����һ������Ϊ n �ַ�������ӡ�����ַ������ַ����������У������������˳�򷵻�����ַ������顣
���������ַ���ABC,��������ַ�A,B,C�������г����������ַ���ABC,ACB,BAC,BCA,CBA��CAB��

���ݷ�Χ��n < 10n<10
Ҫ�󣺿ռ临�Ӷ� O(n!)O(n!)��ʱ�临�Ӷ� O(n!)O(n!)
����������
����һ���ַ���,���Ȳ�����10,�ַ�ֻ������Сд��ĸ��
*/

// �ݹ顢���ݣ���

class Solution {
public:
    void _Permutation(map<char, int>& ch, vector<string>& permut, string ret, int len)
    {
        if (ret.size() == len)
        {
            permut.push_back(ret);
        }

        for (auto& e : ch)
        {
            if (e.second > 0)
            {
                e.second--;
                string tmp = ret;
                ret += e.first;
                //cout << e.first << " " << ret << " ";
                _Permutation(ch, permut, ret, len);
                //����
                ret = tmp;
                e.second++;
            }
        }
    }

    vector<string> Permutation(string str) {
        map<char, int> ch;
        for (auto& e : str)
        {
            ch[e]++;
        }
        int len = str.size();
        vector<string> permut;
        string ret;
        _Permutation(ch, permut, ret, len);
        return permut;
    }
};