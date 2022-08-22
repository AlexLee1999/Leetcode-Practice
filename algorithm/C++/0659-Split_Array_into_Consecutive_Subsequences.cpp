class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> frequency;
        unordered_map<int, int> subsequence;
        for (int i=0; i<nums.size(); ++i) {
            frequency[nums[i]] ++;
        }
        for (int i=0; i<nums.size(); ++i) {
            if (frequency[nums[i]] == 0) {
                continue;
            } else if (subsequence.count(nums[i] - 1) && subsequence[nums[i] - 1] > 0) {
                frequency[nums[i]] --;
                subsequence[nums[i] - 1] --;
                subsequence[nums[i]] ++;
            } else if (frequency[nums[i] + 1] > 0 && frequency[nums[i] + 2] > 0) {
                frequency[nums[i]] --;
                frequency[nums[i] + 1] --;
                frequency[nums[i] + 2] --;
                subsequence[nums[i] + 2] ++;
            } else {
                return false;
            }
        }
        return true;
    }
};
// Time : O(n)
// Space : O(n)