class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> myQueue;
        for (int i=0; i<mat.size(); ++i) {
            for (int j=0; j<mat[0].size(); ++j) {
                if (mat[i][j] == 0) {
                    myQueue.push({i, j});
                } else if (mat[i][j] == 1) {
                    mat[i][j] = INT_MAX;
                }
            }
        }
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                pair<int, int> front = myQueue.front();
                myQueue.pop();
                for (int j=0; j<4; ++j) {
                    int x = front.first + dirs[j].first;
                    int y = front.second + dirs[j].second;
                    if (x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size() && mat[x][y] == INT_MAX) {
                        myQueue.push({x, y});
                        mat[x][y] = step + 1;
                    }
                }
            }
            step ++;
        }
        return mat;
    }
};