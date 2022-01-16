class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (backtrack(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>>& board, const string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        int m = board.size();
        int n = board[0].size();
        if (word.size() == index) {
            return true;
        }
        
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || word[index] != board[i][j]) { //find the word
            return false;
        }
        visited[i][j] = true;
        bool result = backtrack(board, word, i+1, j, index + 1, visited) || backtrack(board, word, i-1, j, index + 1, visited) || backtrack(board, word, i, j+1, index + 1, visited) || backtrack(board, word, i, j-1, index + 1, visited); //find word in four directions
        visited[i][j] = false;
        return result;
    }
};