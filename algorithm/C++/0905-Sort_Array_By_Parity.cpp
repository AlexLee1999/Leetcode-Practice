class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            if (nums[low] & 1 != 0) {
                swap(nums[low], nums[high]);
                high --;
            } else {
                low ++;
            }
        }
        return nums;
    }
};