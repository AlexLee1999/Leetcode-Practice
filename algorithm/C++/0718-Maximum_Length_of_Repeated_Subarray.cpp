class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int max_len = 0;
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (nums1[i] == nums2[j]) {
                    table[i + 1][j + 1] = max(table[i + 1][j + 1], table[i][j] + 1);
                    max_len = max(max_len, table[i + 1][j + 1]);
                }
            }
        }
        return max_len;
    }
};
// Time : O(mn)
// Space : O(mn)