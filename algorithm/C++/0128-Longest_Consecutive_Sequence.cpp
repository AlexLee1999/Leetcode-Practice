class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mySet(nums.begin(), nums.end());
        int len = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (mySet.find(nums[i] - 1) == mySet.end()) {
                int start = nums[i];
                int end = nums[i];
                while (mySet.find(end) != mySet.end()) {
                    len = max(len, end - start + 1);
                    end++;
                }
            }
        }
        return len;
    }
};