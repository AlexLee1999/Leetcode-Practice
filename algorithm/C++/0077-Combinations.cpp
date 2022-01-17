class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> current;
        backtrack(n, 1, k, current, results);
        return results;
    }
    void backtrack(const int& n, int index, const int& k, vector<int>& current, vector<vector<int>>& results) {
        if (current.size() == k) {
            results.push_back(current);
            return;
        }
        if (index > n) {
            return;
        }
        for (int i=index; i<=n; ++i) {
            current.push_back(i);
            backtrack(n, i+1, k, current, results);
            current.pop_back();
        }
    }
};