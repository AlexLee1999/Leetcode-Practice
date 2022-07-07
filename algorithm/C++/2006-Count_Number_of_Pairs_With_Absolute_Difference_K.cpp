class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count = 0;
        for (int i=0; i<nums.size(); ++i) {
            for (int j=i + 1; j < nums.size(); ++j) {
                if (nums[i] - nums[j] == k || nums[i] - nums[j] == -k) {
                    count ++;
                }
            }
        }
        return count;
    }
};
// Time : O(n^2)
// Space : O(1)