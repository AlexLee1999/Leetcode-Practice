class Solution {
public:
    int countArrangement(int n) {
        vector<bool> visited (n, false);
        int count = 0;
        vector<int> cur;
        backtrack(n, visited, count, cur, 0);
        return count;
    }
    void backtrack(int n, vector<bool>& visited, int& count, vector<int>& cur, int idx) {
        if (idx == n) {
            count ++;
            return;
        }
        
        for (int i=0; i<n; ++i) {
            if (!visited[i]) {
                if ((i+1) % (idx + 1) == 0 || (idx + 1) % (i+1) == 0) {
                    cur.push_back(i+1);
                    visited[i] = true;
                    backtrack(n, visited, count, cur, idx + 1);
                    visited[i] = false;
                    cur.pop_back();
                }
            }
        }
    }
};
// Time : O(n!)
// Space : O(n)