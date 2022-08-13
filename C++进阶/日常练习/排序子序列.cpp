#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
来源：牛客网

牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。
牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2
*/

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vv(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        std::cin >> vv[i];
    }

    // 非递增  <  
    // 非递减..>..
    // == 
    int j = 0, count = 0;
    while (j < n)
    {
        if (vv[j] < vv[j + 1]) {
            while (j < n && vv[j] <= vv[j + 1])
                j++;
            count++;
            j++;
        }
        else if (vv[j] > vv[j + 1]) {
            while (j < n && vv[j] >= vv[j + 1])
                j++;
            count++;
            j++;
        }
        else {
            j++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}