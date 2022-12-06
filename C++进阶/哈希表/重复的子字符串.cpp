/*
����һ���ǿյ��ַ��� s ������Ƿ����ͨ��������һ���Ӵ��ظ���ι��ɡ�
*/

class Solution {
public:
    void KMP(string s, int* next, int sz) {
        int j = 0;
        next[j] = 0;
        for (int i = 1; i < sz; ++i) {
            while (j > 0 && s[j] != s[i]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        int sz = s.size();
        if (sz == 0) {
            return false;
        }
        int next[s.size()];
        KMP(s, next, sz);

        if ((next[sz - 1] != 0) && (sz % (sz - next[sz - 1]) == 0)) {
            return true;
        }
        return false;
    }
};
