class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26, 0);
        int len = s1.size();
        int n = s2.size();
        if (len > n) {
            return false;
        }
        for (int i=0; i<len; ++i) {
            count[s1[i] - 'a'] ++;
            count[s2[i] - 'a'] --;
        }
        if (isAllZero(count)) {
            return true;
        }
        for (int i=len; i<n; ++i) {
            count[s2[i] - 'a'] --;
            count[s2[i - len] - 'a'] ++;
            if (isAllZero(count)) {
                return true;
            }
        }
        return false;
    }
    bool isAllZero(vector<int>& arr) {
        for (int i=0; i<arr.size(); ++i) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(l1 + l2)
// Space : O(1)