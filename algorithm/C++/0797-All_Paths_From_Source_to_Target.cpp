class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        vector<vector<int>> ans;
        backtrack(graph, path, ans);
        return ans;
    }
    void backtrack(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& ans) {
        int cur = path.back();
        if (cur == graph.size() - 1) {
            ans.push_back(path);
            return;
        }
        for (int i=0; i<graph[cur].size(); ++i) {
            path.push_back(graph[cur][i]);
            backtrack(graph, path, ans);
            path.pop_back();
        }
    }
};
// Time : O(n!)
// Space : O(n)