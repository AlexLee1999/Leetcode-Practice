class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        uint size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (map.find(target - nums[i]) != map.end()) {
                return vector<int>{i, map[target - nums[i]]};
            }
            map[nums[i]] = i;
        }
        return vector<int> {0, 0};
    }
};
// Time : O(n)
// Space : O(n)
