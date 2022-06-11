class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> myQueue;
        vector<string> digits = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        if (visited.count("0000") != 0) {
            return -1;
        }
        myQueue.push("0000");
        visited.insert("0000");
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int k=0; k<size; ++k) {
                string front = myQueue.front();
                myQueue.pop();
                if (front == target) {
                    return step;
                }
                for (int i=0; i<front.size(); ++i) {
                    for (int j=-1; j<=1; j += 2) {
                        char ch = front[i];
                        string modified = front.substr(0, i) + digits[(ch - '0' + j + 10) % 10] + front.substr(i + 1, 3 - i);
                        if (visited.count(modified) == 0) {
                            visited.insert(modified);
                            myQueue.push(modified);
                        }
                    }
                }
            }            
            step ++;
        }
        return -1;
    }
};
// Time : O(A^n * n^2 + D)
// Space : O(A^n + D)
// D is the deadend size
// A is the digit space (10)
// n is the digit size (4)