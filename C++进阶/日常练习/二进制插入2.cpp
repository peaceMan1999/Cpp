/*

���ӣ�https://www.nowcoder.com/questionTerminal/30c1674ad5694b3f8f0bc2de6f005490
��Դ��ţ����

��������32λ����n��m��ͬʱ����i��j����m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ,
��֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i-j+1�����ж����Ƶ�λ����0��ʼ�ɵ͵��ߡ�

����������
1024��19��2��6
���أ�1100

*/

class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        return n | (m << j);
    }
};