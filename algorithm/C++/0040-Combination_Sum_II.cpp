class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> combinations;
        backtrack(target, 0, candidates, combinations, results);
        return results;
    }
    void backtrack(int target, int start, vector<int>& candidates, vector<int>& combinations, vector<vector<int>>& results) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            vector<int> copy_combinations (combinations.begin(), combinations.end());
            results.push_back(copy_combinations);
            return;
        }
        for (int i=start; i<candidates.size(); ++i) {
            while (i > start && i < candidates.size() && candidates[i] == candidates[i - 1] ){
                i ++;
            }
            if (i >= candidates.size()) {
                return;
            }
            combinations.push_back(candidates[i]);
            backtrack(target - candidates[i], i + 1, candidates, combinations, results);
            combinations.pop_back();
        }
    }
};