// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    void getNext(vector<int>& next, string& needle){
        int i = 1, j = 0; // j是前缀，i是后缀
        next[0] = 0;
        while (i < needle.size()){
            // 前缀不同
            while (j > 0 && needle[i] != needle[j]){
                j = next[j-1]; // 找后缀的前一个
            }
            // 前缀相同
            if (needle[i] == needle[j]){
                j++;
            }
            // next赋值
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
            // 不同
            while (j > 0 && haystack[i] != needle[j]){
                j = next[j-1];
            }
            // 相同
            if (haystack[i] == needle[j]){
                j++;
            }
            // j到尾巴,要+1，因为i还未动
            if (j == needle.size()){
                return i - needle.size()+1;
            }
            i++;
        }
        return -1;
    }
};
