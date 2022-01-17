class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0; 
        // nums[0-zeros-1] = 0
        // nums[zeros-current_ptr-1] = 1
        // nums[current_ptr-twos] unsorted
        // nums[twos+1-end] 2
        int current_ptr = 0;  
        int twos = nums.size()-1;
        while (current_ptr <= twos) {
            if (nums[current_ptr] == 1) {
                current_ptr ++;
            }
            else if (nums[current_ptr] == 0) {
                swap(nums[current_ptr], nums[zeros]);
                current_ptr ++;
                zeros ++;
            } else {
                swap(nums[current_ptr], nums[twos]);
                twos --;
            }
        } 
    }
};