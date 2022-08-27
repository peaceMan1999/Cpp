/*

链接：https://www.nowcoder.com/questionTerminal/30c1674ad5694b3f8f0bc2de6f005490
来源：牛客网

给定两个32位整数n和m，同时给定i和j，将m的二进制数位插入到n的二进制的第j到第i位,
保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1，其中二进制的位数从0开始由低到高。

测试样例：
1024，19，2，6
返回：1100

*/

class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        return n | (m << j);
    }
};