#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

/*
��һ������Ϊ n �����飬��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������[1,2,3,2,2,2,5,4,2]����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��
*/

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int mid = numbers.size() / 2;
		int n = numbers[mid];
		return n;
	}
};

