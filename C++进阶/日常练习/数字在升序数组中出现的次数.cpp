#define _CRT_SECURE_NO_WARNINGS 1

/*
����һ������Ϊ n �ķǽ��������һ���Ǹ������� k ��Ҫ��ͳ�� k �������г��ֵĴ���

���ݷ�Χ��0 \le n \le 1000 , 0 \le k \le 1000��n��1000,0��k��100��
������ÿ��Ԫ�ص�ֵ���� 0 \le val \le 1000��val��100
Ҫ�󣺿ռ临�Ӷ� O(1)��ʱ�临�Ӷ� O(logn)

�ص㣺ʱ�临�Ӷ�Ҫ�ﵽ O(logn)
*/

class Solution {
public:
    int BinarySearch(vector<int>& data, float k)
    {
        // ���ֲ���
        int left = 0, right = data.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (data[mid] < k)
                left = mid + 1;
            else if (data[mid] > k)
                right = mid - 1;
        }
        return left;
    }

    int GetNumberOfK(vector<int> data, int k) {
        // ��� 3.5 �� 2.5 ��λ�������
        return BinarySearch(data, k + 0.5) - BinarySearch(data, k - 0.5);
    }
};