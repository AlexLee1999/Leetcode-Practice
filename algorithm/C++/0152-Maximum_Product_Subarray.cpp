class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int current_max = nums[0];
        int current_min = nums[0];
        int result = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            int temp_max = max(current_max * nums[i], max(current_min * nums[i], nums[i]));         
            current_min = min(current_max * nums[i], min(current_min * nums[i], nums[i]));
            current_max = temp_max;
            result = max(result, current_max);
        }
        return result;
    }
};