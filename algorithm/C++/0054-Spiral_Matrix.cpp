class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<int> res;
        int x=-1;
        int y=0;
        vector<vector<bool>> table(n, vector<bool>(m, false));
        while (true) {
            while (x < m-1 && !table[y][x+1]) {
                x++;
                res.push_back(matrix[y][x]);
                table[y][x] = true;
            }
            while (y < n-1 && !table[y+1][x]) {
                y++;
                res.push_back(matrix[y][x]);
                table[y][x] = true;
            }
            while (x > 0 && !table[y][x-1]) {
                x--;
                res.push_back(matrix[y][x]);
                table[y][x] = true;
            }
            while (y > 0 && !table[y-1][x]) {
                y--;
                res.push_back(matrix[y][x]);
                table[y][x] = true;
            }
            if (!(y > 0 && !table[y-1][x]) && !(x > 0 && !table[y][x-1]) && !(y < n-1 && !table[y+1][x]) && !(x < m-1 && !table[y][x+1])) {
                break;
            }
        }
        return res;
    }
};
