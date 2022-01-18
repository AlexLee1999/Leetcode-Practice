class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i=0; i<nums.size()-2; ++i) {
            int left = i+1;
            int right = nums.size()-1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] >= target) {
                    right --;
                } else {
                    result += (right - left); 
                    // right-left = number of possibilities that is smaller than target
                    left ++;
                }
            }
        }
        return result;
    }
};