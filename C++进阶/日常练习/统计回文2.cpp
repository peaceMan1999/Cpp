#define _CRT_SECURE_NO_WARNINGS 1

/*

�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
�������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ���
����ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ���
����ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
���磺
A = ��aba����B = ��b����������4�ְ�B����A�İ취��
* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
* �ڵ�һ����ĸ��a��֮��: "abba" �ǻ���
* ����ĸ��b��֮��: "abba" �ǻ���
* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
�������������Ĵ�Ϊ2

*/


#include <iostream>
#include <string>

int IsReverse(std::string& tmp)
{
    int i = 0, j = tmp.size() - 1;
    while (i < j)
    {
        if (tmp[i] != tmp[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    std::string str;
    std::string ch;
    getline(std::cin, str);
    getline(std::cin, ch);

    int count = 0;
    for (int i = 0; i <= str.size(); i++)
    {
        // ע�����ﲻҪ�ı�str��
        std::string tmp = str;
        tmp.insert(i, ch);

        if (IsReverse(tmp)) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}





