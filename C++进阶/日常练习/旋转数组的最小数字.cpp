#define _CRT_SECURE_NO_WARNINGS 1

/*
��һ������Ϊ n �ķǽ������飬����[1,2,3,4,5]������������ת������һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ��
���һ����ת���飬��������[3,4,5,1,2]������[4,5,1,2,3]�����ġ����ʣ���������һ����ת���飬�������е���Сֵ��

���ݷ�Χ��1 \le n \le 100001��n��10000������������Ԫ�ص�ֵ: 0 \le val \le 100000��val��10000
Ҫ�󣺿ռ临�Ӷȣ�O(1)O(1) ��ʱ�临�Ӷȣ�O(logn)O(logn)
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 1)
            return rotateArray[0];
        int left = 0, right = rotateArray.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            // �� > ��
            if (rotateArray[right] > rotateArray[mid])
                right = mid; // ����Ҫ�����м�
            // �� < ��
            else if (rotateArray[right] < rotateArray[mid])
                left = mid + 1;
            // �� = ��
            else
                right--;
        }
        return rotateArray[left];
    }
};