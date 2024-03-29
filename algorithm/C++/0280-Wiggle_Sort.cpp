class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool greater = true;
        for (int i=0; i<nums.size()-1; ++i) {
            if (greater) {
                if (nums[i] > nums[i+1]) {
                    swap(nums[i], nums[i+1]);
                }
            } else {
                if (nums[i] < nums[i+1]) {
                    swap(nums[i], nums[i+1]);
                }
            }
            greater = !greater;
        }
    }
};
// Time : O(n)
// Space : O(1)