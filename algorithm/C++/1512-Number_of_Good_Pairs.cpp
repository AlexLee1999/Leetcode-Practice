class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int num = 0;
        for (int i=0; i<nums.size(); ++i) {
            for (int j=i+1; j<nums.size(); ++j) {
                if (nums[i] == nums[j]) {
                    num ++;
                }
            }
        }
        return num;
    }
};
// Time : O(n^2)
// Space : O(1)