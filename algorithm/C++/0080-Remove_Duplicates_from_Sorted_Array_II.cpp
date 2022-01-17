class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1; // slow pointer, the index need to overlap
        int count = 1;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) {
                count ++;
            } else {
                count = 1;
            }
            if (count <= 2) {
                nums[j] = nums[i];
                j ++;
            }
        }
        return j;
    }
};