// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    void getNext(vector<int>& next, string& needle){
        int i = 1, j = 0; // j��ǰ׺��i�Ǻ�׺
        next[0] = 0;
        while (i < needle.size()){
            // ǰ׺��ͬ
            while (j > 0 && needle[i] != needle[j]){
                j = next[j-1]; // �Һ�׺��ǰһ��
            }
            // ǰ׺��ͬ
            if (needle[i] == needle[j]){
                j++;
            }
            // next��ֵ
            next[i] = j;
            i++;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0){
            return 0;
        }
        int len = needle.size();
        vector<int> next(len, 0);
        getNext(next, needle);

        int i = 0, j = 0;
        while (i < haystack.size()){
            // ��ͬ
            while (j > 0 && haystack[i] != needle[j]){
                j = next[j-1];
            }
            // ��ͬ
            if (haystack[i] == needle[j]){
                j++;
            }
            // j��β��,Ҫ+1����Ϊi��δ��
            if (j == needle.size()){
                return i - needle.size()+1;
            }
            i++;
        }
        return -1;
    }
};
