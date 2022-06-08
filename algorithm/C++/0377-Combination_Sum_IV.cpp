class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> table (target + 1, 0);
        table[0] = 1;
        for (int i=1; i<=target; ++i) {
            for (int j=0; j<nums.size(); ++j) {
                if (i - nums[j] >= 0) {
                    table[i] += table[i - nums[j]];
                }
            }
        }
        return table[target];
    }
};
// Time : O(Tn)
// Space : O(T) T is the target