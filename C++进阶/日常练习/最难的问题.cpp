#define _CRT_SECURE_NO_WARNINGS 1

/*

链接：https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b
来源：牛客网

NowCoder生活在充满危险和阴谋的年代。为了生存，他首次发明了密码，用于军队的消息传递。假设你是军团中的一名军官，需要把发送来的消息破译出来、并提
供给你的将军。
消息加密的办法是：对消息原文中的每个字母，分别用该字母之后的第5个字母替换（例如：消息原文中的每个字母A 都分别替换成字母F），其他字符不 变，并且消息原文的所有字母都是大写的。密码中的字母与原文中的字母对应关系如下。
密码字母：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
原文字母：V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

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
