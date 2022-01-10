class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> combination;
        backtrack(n, k, combination, 1, results);
        return results;
    }
    void backtrack(int target, int target_num, vector<int>& combination, int current_num, vector<vector<int>>& results) {
        if (target == 0 && combination.size() == target_num) {
            vector<int> copy_combination(combination.begin(), combination.end());
            results.push_back(copy_combination);
            return;
        }
        if (target < 0) {
            return;
        }
        if (combination.size() == target_num) {
            return;
        }
        for (int i=current_num; i<10; ++i) {
            combination.push_back(i);
            backtrack(target - i, target_num, combination, i + 1, results);
            combination.pop_back();
        }
    }
};