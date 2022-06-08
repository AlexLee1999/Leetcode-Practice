class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        set<vector<vector<int>>> visited;
        queue<vector<vector<int>>> myQueue;
        myQueue.push(mat);
        visited.insert(mat);
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                vector<vector<int>> front = myQueue.front();
                myQueue.pop();
                if (isZero(front)) {
                    return step;
                }
                for (int j=0; j<mat.size(); ++j) {
                    for (int k=0; k<mat[0].size(); ++k) {
                        vector<vector<int>> old_mat = front;
                        flip(front, j, k);
                        if (!visited.count(front)) {
                            myQueue.push(front);
                            visited.insert(front);
                        }
                        flip(front, j, k);
                    }
                }
            }
            step ++;
        }
        return -1;
    }
    void flip(vector<vector<int>>& mat, int row, int col) {
        if (row + 1 < mat.size()) {
            mat[row + 1][col] = mat[row + 1][col] == 0 ? 1 : 0;
        }
        if (row - 1 >= 0) {
            mat[row - 1][col] = mat[row - 1][col] == 0 ? 1 : 0;
        }
        if (col - 1 >= 0) {
            mat[row][col - 1] = mat[row][col - 1] == 0 ? 1 : 0;
        }
        if (col + 1 < mat[0].size()) {
            mat[row][col + 1] = mat[row][col + 1] == 0 ? 1 : 0;
        }
        mat[row][col] = mat[row][col] == 0 ? 1 : 0;
    }
    bool isZero(vector<vector<int>>& mat) {
        for (int i=0; i<mat.size(); ++i) {
            for (int j=0; j<mat[0].size(); ++j) {
                if (mat[i][j] == 1) {
                    return false;
                }
            }
        }
        return true;
    }
};