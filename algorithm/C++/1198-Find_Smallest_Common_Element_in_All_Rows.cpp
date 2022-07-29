class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int> count(10001, 0);
        for (int i=0; i<mat.size(); ++i) {
            for (int j=0; j<mat[0].size(); ++j) {
                count[mat[i][j]] ++;
            }
        }
        int max_num = 0;
        int max_val = 0;
        for (int i=0; i<=10000; ++i) {
            if (max_val < count[i]) {
                max_num = i;
                max_val = count[i];
            }
        }
        return max_val == mat.size() ? max_num : -1;
    }
};
// Time : O(mn)
// Space : O(k)