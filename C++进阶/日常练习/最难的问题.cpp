#define _CRT_SECURE_NO_WARNINGS 1

/*

���ӣ�https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b
��Դ��ţ����

NowCoder�����ڳ���Σ�պ���ı�������Ϊ�����棬���״η��������룬���ھ��ӵ���Ϣ���ݡ��������Ǿ����е�һ�����٣���Ҫ�ѷ���������Ϣ�������������
������Ľ�����
��Ϣ���ܵİ취�ǣ�����Ϣԭ���е�ÿ����ĸ���ֱ��ø���ĸ֮��ĵ�5����ĸ�滻�����磺��Ϣԭ���е�ÿ����ĸA ���ֱ��滻����ĸF���������ַ��� �䣬������Ϣԭ�ĵ�������ĸ���Ǵ�д�ġ������е���ĸ��ԭ���е���ĸ��Ӧ��ϵ���¡�
������ĸ��A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
ԭ����ĸ��V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

*/

// write your code here cpp
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c = (c <= 'E') ? c += 21 : c -= 5;
        }
        cout << c;
        //putchar(c);
    }
    return 0;
}
