class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int left_max = 0;
        int right_max = 0;
        int result = 0;
        while (left < right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if (left_max < right_max) { 
                //if left_max < right_max, we can guarentee that the lowest right is higher than left, therefore add the water
                result += max(0, left_max - height[left]);
                left ++;
            } else {
                result += max(0, right_max - height[right]);
                right --;
            }
        }
        return result;
    }
};