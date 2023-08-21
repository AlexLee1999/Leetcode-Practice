class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        long long l = nums[left];
        long long r = nums[right];
        int count = 0;
        while (left < right) {
           if (l == r) {
               left ++;
               right --;
               l = nums[left];
               r = nums[right];
            } else if (l < r) {
                left ++;
                l += nums[left];
                count ++;
            } else if (l > r) {
                right --;
                r += nums[right];
                count ++;
            }
        }
        return count;
    }
};