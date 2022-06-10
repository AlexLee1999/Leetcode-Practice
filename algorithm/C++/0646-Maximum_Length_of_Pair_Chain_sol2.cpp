class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]){
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        });
        vector<int> table(pairs.size(), 1);
        for (int i=1; i<pairs.size(); ++i) {
            for (int j=0; j<i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    table[i] = max(table[i], table[j] + 1);
                }
            }
        }
        int max_len = 0;
        for (int i=0; i<table.size(); ++i) {
            max_len = max(max_len, table[i]);
        }
        return max_len;
    }
};
// Time : O(N^2) Dynamic programming
// Space : O(N)