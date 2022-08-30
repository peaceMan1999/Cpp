/*

�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��
A��������Ҫ���ţ�������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡�
�����������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס�
���ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�

������ɫ����n(1��n��13),ͬʱ������������Ϊn������left,right,�ֱ����ÿ����ɫ���������׵�������
���ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�����

4,[0,7,1,6],[1,5,0,6]
���أ�10(���ͣ�������������ȡ2ֻ����������ȡ8ֻ)

*/



class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int sum = 0;
        int left_sum = 0, right_sum = 0, left_min = INT_MAX, right_min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (left[i] * right[i] == 0) {
                sum += (left[i] + right[i]);
            }
            else {
                left_sum += left[i];
                left_min = left[i] < left_min ? left[i] : left_min;
                right_sum += right[i];
                right_min = right[i] < right_min ? right[i] : right_min;
            }
        }

        return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
    }
};





