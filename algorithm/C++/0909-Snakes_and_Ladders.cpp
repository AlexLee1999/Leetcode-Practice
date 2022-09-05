class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> line = {0};
        int max = board.size() * board.size();
        reverse(board.begin(), board.end());
        for (int i=0; i < board.size(); ++i) {
            if ((i & 1) == 1) {
                reverse(board[i].begin(), board[i].end());
            }
            line.insert(line.end(), board[i].begin(), board[i].end());
        }
        queue<int> myQueue;
        vector<bool> visited(line.size(), false);
        myQueue.push(1);
        visited[1] = true;
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                int front = myQueue.front();
                myQueue.pop();
                if (front == max) {
                    return step;
                }
                for (int j=1; j<=min(max - front, 6); ++j) {
                    int dest = front + j;
                    if (!visited[dest]) {
                        visited[dest] = true;
                        if (line[dest] == -1) {
                            myQueue.push(dest);
                        } else {
                            myQueue.push(line[dest]);
                        }
                    }
                }
            }
            step ++;
        }
        return -1;
    }
};
// Time : O(n^2)
// Space : O(n^2)