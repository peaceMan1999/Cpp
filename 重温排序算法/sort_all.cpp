#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


using namespace std;

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

//// 右边先走！！！
//
//int _QuickSort(int* arr, int left, int right) {
//	// 随机取数
//	int index = rand() % (right - left + 1) + left;
//	Swap(arr[index], arr[left]);
//
//	// 开始
//	int num = arr[left];
//	int l = left, r = right;
//	while (l < r) {
//
//		while (l < r && num <= arr[r]) {
//			r--;
//		}
//		while (l < r && num >= arr[l]) {
//			l++;
//		}
//		Swap(arr[l], arr[r]);
//
//	}
//	if (arr[l] < num) {
//		Swap(arr[left], arr[l]);
//	}
//	return l;
//}
//
//// 快排
//void QuickSort(int* arr, int left, int right) {
//	// 返回
//	if (left >= right) {
//		return;
//	}
//	// 子排序
//	int meet = _QuickSort(arr, left, right);
//	// 递归
//	QuickSort(arr, left, meet-1);
//	QuickSort(arr, meet+1, right);
//}
//
//
//// 冒泡排序
//void Bubble(int* arr, int len) {
//	for (int i = len-1; i > 0; --i) {
//		int count = 0; // 提高效率
//		for (int j = i - 1; j >= 0; --j) {
//			if (arr[j] > arr[i]) {
//				Swap(arr[i], arr[j]);
//				count = 1;
//			}
//		}
//		if (count == 0) {
//			break;
//		}
//	}
//}
//
//// 插入排序
//// 类似于挖坑，先把最右值提出来，大于就向后覆盖，最后填坑
//void InsertSort(int *arr, int len) {
//	// 记得要减一
//	for (int i = 0; i < len - 1; ++i) {
//		int end = i;
//		int key = arr[end + 1]; // 挖坑
//		while (end >= 0) {
//			if (arr[end] > key) {
//				arr[end + 1] = arr[end];
//				end--;
//			}
//			else {
//				break;
//			}
//		}
//		// 填坑
//		arr[end + 1] = key;
//	}
//}
//
//// 选择排序 -- 前后指针
//void ChoiceSort(int *arr, int len) {
//	int left = 0, right = len - 1;
//	
//	while (left < right) {
//		int minf = left, maxf = left;
//
//		for (int i = left; i <= right; ++i) {
//			if (arr[i] > arr[maxf]) {
//				maxf = i;
//			}
//			if (arr[i] < arr[minf]) {
//				minf = i;
//			}
//		}
//		Swap(arr[minf], arr[left]);
//		// 需要判断最大值是否位左值
//		if (maxf == left) {
//			maxf = minf;
//		}
//		Swap(arr[maxf], arr[right]);
//		left++, right--;
//	}
//
//}

//void ShellSort(int* arr, int len) {
//	int gap = len / 3 + 1;
//
//	while (gap > 1) {
//		for (int i = 0; i < len - gap; ++i) {
//			int end = i;
//			int tmp = arr[end + gap];
//			// 就是类似插入排序
//			while (end >= 0) {
//				if (arr[end] > tmp) {
//					arr[end + gap] = arr[end];
//					end -= gap;
//				}
//				else {
//					break;
//				}
//			}
//			// 填坑
//			arr[end + gap] = tmp;
//		}
//		for (int i = 0; i < len; ++i) {
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//		gap = gap / 3 + 1;
//	}
//	// 插入排序
//	for (int i = 0; i < len-1; ++i) {
//		int end = i;
//		int tmp = arr[i + 1];
//		while (end >= 0) {
//			if (arr[end] > tmp) {
//				arr[end + 1] = arr[end];
//				end--;
//			}
//			else {
//				break;
//			}
//		}
//		arr[end + 1] = tmp;
//	}
//}

//// 向下建堆大堆
//void AdjustDown(int *arr, int parent, int len) {
//	int child = parent * 2 + 1; // 左子
//
//	while (child < len) {
//		if (child + 1 < len && arr[child + 1] > arr[child]) {
//			child++;
//		}
//		if (arr[child] > arr[parent]) {
//			Swap(arr[child], arr[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else {
//			break;
//		}
//	}
//}
//
//void HeapSort(int *arr, int len) {
//	// len-1-》左子-1-》下标/2-》父亲
//	for (int i = len - 1 - 1 / 2; i >= 0; --i) {
//		AdjustDown(arr, i, len);
//	}
//
//	// 排序
//	for (int i = len - 1; i >= 0; --i) {
//		Swap(arr[i], arr[0]);
//		AdjustDown(arr, 0, i);
//	}
//}

//void Merge(int* arr, int* tmp, int begin1, int end1, int begin2, int end2) {
//	// 记录j
//	int i = begin1, j = i;
//	
//	while (begin1 <= end1 && begin2 <= end2) {
//		if (arr[begin1] < arr[begin2]) {
//			tmp[i++] = arr[begin1++];
//		}
//		else {
//			tmp[i++] = arr[begin2++];
//		}
//	}
//	while (begin1 <= end1) {
//		tmp[i++] = arr[begin1++];
//	}
//	while (begin2 <= end2) {
//		tmp[i++] = arr[begin2++];
//	} 
//
//	// 赋值
//	for (; j < i; ++j) {
//		arr[j] = tmp[j];
//	}
//}
//
//void _MergeSort(int *arr, int *tmp, int begin, int end) {
//	if (begin >= end) {
//		return;
//	}
//	int mid = (begin + end) >> 1;
//	// 必须要mid，不能mid-1，因为可能为-1，越界了
//	_MergeSort(arr, tmp, begin, mid);
//	_MergeSort(arr, tmp, mid + 1, end);
//
//	// 排序
//	int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
//	Merge(arr, tmp, begin1, end1, begin2, end2);
//}
//
//// 归并
//void MergeSort(int* arr, int len) {
//	int* tmp = (int*)malloc(sizeof(int) * len);
//	if (tmp == NULL){
//		cerr << "malloc err" << endl;
//		return;
//	}
//	_MergeSort(arr, tmp, 0, len-1);
//
//	free(tmp);
//}
//

#include <stack>

//
//int _QuickSort(int* arr, int begin, int end) {
//	int tmp = rand() % (end - begin + 1) + begin;
//	Swap(arr[begin], arr[tmp]);
//
//	int left = begin, right = end;
//	// < 不是 <=
//	while (left < right) {
//		while (left < right && arr[right] >= arr[begin]) {
//			right--;
//		}
//		while (left < right && arr[left] <= arr[begin]) {
//			left++;
//		}
//		Swap(arr[left], arr[right]);
//	}
//	if (arr[left] < arr[begin]){
//		Swap(arr[left], arr[begin]);
//	}
//	return left;
//}
//
//// 非递归快排
//void QuickSortNonR(int *arr, int len) {
//	stack<int> st;
//	st.push(0);
//	st.push(len - 1);
//	
//	// 栈空了就说明排序完
//	while (!st.empty()) {
//		int end = st.top();
//		st.pop();
//
//		int begin = st.top();
//		st.pop();
//
//		int meet = _QuickSort(arr, begin, end);
//
//		if (meet - 1 > begin) {
//			st.push(begin);
//			st.push(meet - 1);
//		}
//		if (meet + 1 < end) {
//			st.push(meet + 1);
//			st.push(end);
//		}
//	}
//}


void Merge(int* arr, int *tmp, int begin1, int end1, int begin2, int end2) {
	int i = begin1, j = i;

	while (begin1 <= end1 && begin2 <= end2) {
		if (arr[begin1] < arr[begin2]) {
			tmp[i++] = arr[begin1++];
		}
		else {
			tmp[i++] = arr[begin2++];
		}
	}
	while (begin1 <= end1) {
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end1) {
		tmp[i++] = arr[begin2++];
	}

	for (; j < i; j++) {
		arr[j] = tmp[j];
	}
}

void MergeSortNonR(int *arr, int len){
	int* tmp = (int*)malloc(sizeof(int) * len);
	assert(tmp);
	
	int left = 0, right = len - 1;
	int gap = 1;
	
	// 逆序
	while (gap < right) {
		// 留1所以是right不是len
		for (int i = 0; i < right; i += gap * 2) {
			//[i, i+gap-1][i+gap, i+gap*2-1]
			int begin1 = i, end1 = i + gap - 1, begin2 = i + gap, end2 = i + gap * 2 - 1;
			// 情况1，end1超过right
			if (end1 > right) {
				break;
			}
			// 情况2，end2超过right
			if (end2 > right) {
				end2 = right;
			}

			Merge(arr, tmp, begin1, end1, begin2, end2);
		}
		gap *= 2;
	}

}

// 计数排序
void CountSort(int* arr, int len) {
	int maxf = arr[0], minf = arr[0];

	for (int i = 0; i < len; ++i) {
		maxf = max(maxf, arr[i]);
		minf = min(minf, arr[i]);
	}
	int gap = maxf - minf + 1;
	// 相对映射
	int* tmp = (int*)malloc(sizeof(int) * gap);

	// 一定要初始化
	memset(tmp, 0, sizeof(int)*gap);
	assert(tmp);

	for (int i = 0; i < len; ++i) {
		tmp[arr[i] + minf]++;
	}

	int j = 0;
	for (int i = 0; i < gap; ++i) {
		while (tmp[i] > 0) {
			arr[j++] = i + minf;
			tmp[i]--;
		}
	}

	free(tmp);
}

void test1() {
	int arr[] = { 5, 7, 1, 2, 9, 0, 1, 8, 10 ,4 };
	int len = sizeof(arr) / sizeof(int);
	//QuickSort(arr, 0, len - 1);
	//Bubble(arr, len);
	//InsertSort(arr, len);
	//ShellSort(arr, len);
	//HeapSort(arr, len);
	//MergeSort(arr, len);
	//QuickSortNonR(arr, len);
	//MergeSortNonR(arr, len);
	CountSort(arr, len);

	for (int i = 0; i < len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//void test2() {
//	int port = rand() % 9;
//	cout << port << endl;
//}

int main() {
	srand(time(NULL));
	test1();
	//test2();
	return 0;
}