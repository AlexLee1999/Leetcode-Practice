class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        string str = s;
        while (str.size() > 1) {
            int idx = str.find(str.back());
            if (idx == str.size() - 1) {
                ans += idx / 2;
            } else {
                str.erase(idx, 1);
                ans += idx;
            }
            str.pop_back();
        }
        return ans;
    }
};
// Time : O(n^2)
// Space : O(n)