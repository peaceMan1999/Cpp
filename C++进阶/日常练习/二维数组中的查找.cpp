#define _CRT_SECURE_NO_WARNINGS 1

/*
��һ����ά����array�У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
[
[1,2,8,9],
[2,4,9,12],
[4,7,10,13],
[6,8,11,15]
]
���� target = 7������ true��

���� target = 3������ false��

���ݷ�Χ������ĳ������� 0 \le n,m \le 5000��n,m��500 �� �����е�ֵ���� 0 \le val \le 10^90��val��10
9

���ף��ռ临�Ӷ� O(1)O(1) ��ʱ�临�Ӷ� O(n+m)O(n+m)
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty())
            return false;
        if (array[0].empty())
            return false;
        for (int i = array.size() - 1, j = 0; i >= 0 && j < array[i].size();)
        {
            if (array[i][j] > target) // ����������
                i--;
            else if (array[i][j] < target) // С��������
                j++;
            else // �����Ե�
                return true;
        }
        return false;
    }
};