class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        vector<int> result;
        while (i < n) {
            int j = nums[i] - 1;
            if (j >=0 && j < n && nums[i] != nums[j]) {
                swap(nums[i], nums[j]);
            } else {
                ++ i;
            }
        }
        for (int i=0; i<n; ++i) {
            if (nums[i] != i+1) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};