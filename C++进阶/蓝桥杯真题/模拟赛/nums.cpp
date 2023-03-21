#include <iostream>
#include <vector>

using namespace std;

long long fmin(long long a, long long b){
	return a < b ? a : b;
}

int main()
{
	long long n;
	cin >> n;
	vector<long long> nums(n, 0);
	vector<long long> ans(n, 0);
	for (long long i = 0; i < n; ++i){
		cin >> nums[i];
//		cout << nums[i] << " ";
	}
	long long k;
	cin >> k;
	
	// 遍历 
	for (long long i = 0; i < n; ++i){
		long long left = i-k;
		long long right = i+k;
		while (left < 0 && left < i){
			left++;
		}
		while (right >= n && right > i){
			right--;
		}
		long long ffmin = nums[i];
		for (long long j = left; j <= right; ++j){
//			cout << "下标" << i << " " << j << endl;
//			cout << "数值" << nums[i] << " " << nums[j] << endl;
			ffmin = fmin(fmin(nums[j], nums[i]), ffmin);
		} 
//		for (int j = i - k; j >= 0 && j < n; ++j){
//			cout << i << " " << j << endl;
//			ans[i] = min(nums[j], nums[i]);
//		} 
		ans[i] = ffmin;
//		cout << "--答案--" << ans[i] << endl;
	}
	
	for (long long i = 0; i < n; ++i){
		cout << ans[i] << " ";
	}
	
	return 0;
}

