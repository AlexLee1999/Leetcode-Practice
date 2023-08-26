class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> arr;
        for (int i=0; i<nums.size(); ++i) {
            auto it = upper_bound(arr.begin(), arr.end(), nums[i]);
            if (it == arr.end()) {
                arr.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return nums.size() - arr.size();
    }
};