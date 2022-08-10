class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int left = 1;
        int right = s.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (search(s, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    bool search(string s, int len) {
        unordered_set<string> mySet;
        int n = s.size();
        for (int i=0; i<=n-len; ++i) {
            string substr = s.substr(i, len);
            if (mySet.count(substr)) {
                return true;
            }
            mySet.insert(substr);
        }
        return false;
    }
};
// Time : O(nlogn)
// Space : O(n)