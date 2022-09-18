/*

���ӣ�https://www.nowcoder.com/questionTerminal/296c2c18037843a7b719cf4c9c0144e4
��Դ��ţ����

����һ��ȫ������������arr������һ��arr����С������ɺ͵ĸ��
1��arr�����зǿ��Ӽ��У���ÿ���Ӽ��ڵ�����Ԫ�ؼ���������ֺܶ��ֵ��������С�ļ�Ϊmin�����ļ�Ϊmax��
2��������[min,max]�ϣ������һЩ���������Ա�arrĳһ���Ӽ���ӵõ�����ô��Щ��������С���Ǹ���
����arr����С������ɺͣ� 3��������[min,max]�ϣ�������е��������Ա�arr��ĳһ���Ӽ���ӵõ���
��ômax+1��arr����С������ɺͣ� ������ arr = {3,2,5} arr��minΪ2��maxΪ10��������[2,10]�ϣ�
4�ǲ��ܱ��κ�һ���Ӽ���ӵõ���ֵ����С�ģ�����4��arr����С������ɺͣ� arr = {3,2,4} arr��minΪ2��
maxΪ9��������[2,9]�ϣ�8�ǲ��ܱ��κ�һ���Ӽ���ӵõ���ֵ����С�ģ�����8��arr����С������ɺͣ�
arr = {3,1,2} arr��minΪ1��maxΪ6��������[2,6]�ϣ��κ��������Ա�ĳһ���Ӽ���ӵõ���
����7��arr����С������ɺͣ� ��д��������arr����С������ɺ͡�

*/

class Solution {
public:
    /**
     *	���������е���С������ɺ�
     *	���룺��������arr
     *	���أ����������е���С������ɺ�
     */
    int getFirstUnFormedNum(vector<int> arr, int len) {
        //int arr[] = {3, 2, 5};
        int min = arr[0], max = 0;
        for (int i = 0; i < len; i++)
        {
            max += arr[i];
            if (min > arr[i])
                min = arr[i];
        }

        vector<int> pack(max + 1, 0); // max = 10

        for (int i = 0; i < len; i++)
        {
            for (int j = max; j >= arr[i]; j--)
            {
                if (j - pack[j] >= arr[i])
                    pack[j] += arr[i];
                else if (pack[j] < pack[j - arr[i]] + arr[i])
                    pack[j] = arr[i] + pack[j - arr[i]];
            }
        }

        for (int i = min; i <= max; i++)
        {
            if (pack[i] != i)
                return i;
        }
        return max + 1;

    }
};


