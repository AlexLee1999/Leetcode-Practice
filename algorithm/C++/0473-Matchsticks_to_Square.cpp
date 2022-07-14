class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        int n = matchsticks.size();
        for (int i=0; i<n; ++i) {
            sum += matchsticks[i];
        }
        
        if (n < 4 || sum % 4 != 0) {
            return false;
        }
        vector<bool> visited(n, false);
        return backtrack(matchsticks, sum / 4, 0, 0, 0, visited);
        
    }
    bool backtrack(vector<int>& matchsticks, int target, int cur, int count, int idx, vector<bool>& visited) {
        if (count == 3) {
            return true;
        }
        if (cur > target) {
            return false;
        }
        if (cur == target) {
            return backtrack(matchsticks, target, 0, count + 1, 0, visited);
        }
        for (int i=idx; i<matchsticks.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                if (backtrack(matchsticks, target, cur + matchsticks[i], count, i + 1, visited)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
};