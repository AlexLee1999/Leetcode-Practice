class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        int ans = 0;
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (picture[i][j] == 'B') {
                    row[i] ++;
                    col[j] ++;
                }
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1) {
                    ans ++;
                }
            }
        }
        return ans;
    }
};
// Time : O(mn)
// Space : O(m + n)