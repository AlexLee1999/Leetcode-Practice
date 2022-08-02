class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) {
            return mat;
        }
        queue<int> myQueue;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                myQueue.push(mat[i][j]);
            }
        }
        vector<vector<int>> ans;
        for (int i=0; i<r; ++i) {
            vector<int> tmp;
            for (int j=0; j<c; ++j) {
                tmp.push_back(myQueue.front());
                myQueue.pop();
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
// Time : O(mn)
// Space : O(mn)