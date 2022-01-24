class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for (int i=0; i<nums.size(); ++i) {
            ones = ones^nums[i] & (~twos); //add to ones and remove twos 0->1, 2->3
            twos = twos^nums[i] & (~ones); //add to twos and remove ones 1->2
        }
        return ones;
    }
};