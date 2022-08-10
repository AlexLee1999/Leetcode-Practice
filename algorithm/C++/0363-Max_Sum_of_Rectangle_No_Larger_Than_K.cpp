class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        for (int i=0; i<n; ++i) {
            vector<int> sum(m, 0);
            for (int j=i; j<n; ++j) {
                for (int k=0; k<m; ++k) {
                    sum[k] += matrix[k][j];
                }
                int cur_sum = 0;
                set<int> mySet;
                mySet.insert(0);
                for (int l=0; l<sum.size(); ++l) {
                    cur_sum += sum[l];
                    auto it = mySet.lower_bound(cur_sum - k);
                    if (it != mySet.end()) {
                        ans = max(ans, cur_sum - *it);
                    }
                    mySet.insert(cur_sum);
                }   
            }
        }
        return ans;
    }
};
// Time : O(rc^2log(r))
// Space : O(r)