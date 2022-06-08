class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> table(s.size(), vector<bool>(s.size(), false));
        for (int right=0; right < s.size(); ++right) {
            for (int left = 0; left <= right; ++left) {
                if (s[left] == s[right]) {
                   if (right - left <= 2 || table[left + 1][right - 1]) { //first find if the substr is palindrome
                       table[left][right] = true;
                   } 
                }
                
            }
        }
        vector<int> mincut_table(s.size(), 0);
        for (int i=0; i<s.size(); ++i) {
            int mincut = i; // the maximum cut is the length
            for (int j=0; j<=i; ++j) {
                if (table[j][i]) {
                    if (j == 0) {
                        mincut = 0; //don't need to cut
                    } else {
                        mincut = min(mincut, mincut_table[j - 1] + 1);
                    }
                }
            }
            mincut_table[i] = mincut;
        }
        return mincut_table[s.size() - 1];
    }
};
// Time : O(n^2)
// Space : O(n^2)
