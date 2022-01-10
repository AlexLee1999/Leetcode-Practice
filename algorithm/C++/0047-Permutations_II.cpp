class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> sub_result;
        unordered_map<int, int> my_map;
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            my_map[nums[i]] ++;
        }
        backtrack(nums, results, sub_result, my_map, n);
        return results;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& results, vector<int>& sub_result, unordered_map<int, int>& my_map, int size) {
        if (size == sub_result.size()) {
            results.push_back(sub_result);
            return;
        }
        for (auto it = my_map.begin(); it != my_map.end(); ++it) {
            if(it->second != 0) {
                sub_result.push_back(it->first);
                it->second --;
                backtrack(nums, results, sub_result, my_map, size);
                it->second ++;
                sub_result.pop_back();
            }
        }
        
    }
};