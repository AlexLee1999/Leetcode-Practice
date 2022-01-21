class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<pair<int, int>> dirs{{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
        vector<vector<bool>> visited(607, vector<bool>(607, false));
        queue<pair<int, int>> myQueue;
        myQueue.push({0, 0});
        if (x == 0 && y == 0) {
            return 0;
        }
        int depth = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            depth ++;
            for (int i=0; i<size; ++i) {
                pair<int, int> front = myQueue.front();
                myQueue.pop();
                int first;
                int second;
                for (int j=0; j<8; ++j) {
                    first = front.first + dirs[j].first;                    
                    second = front.second + dirs[j].second;
                    if (first == x && second == y) {
                        return depth;
                    } else if ((abs(first) + abs(second)) <= 300) {
                        if (!visited[first+302][second+302]) {
                            myQueue.push({first, second});
                            visited[first+302][second+302] = true;
                        }
                    } else {
                        continue;
                    }
                }
            }
        }
        return depth;
    }
};