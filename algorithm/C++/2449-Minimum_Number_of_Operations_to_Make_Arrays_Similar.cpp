class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<int> target_odd;
        vector<int> target_even;
        vector<int> nums_odd;
        vector<int> nums_even;
        long long ans = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                nums_even.push_back(nums[i]);
            } else {
                nums_odd.push_back(nums[i]);
            }
            if (target[i] % 2 == 0) {
                target_even.push_back(target[i]);
            } else {
                target_odd.push_back(target[i]);
            }
        }
        for (int i=0; i<target_even.size(); ++i) {
            if (target_even[i] > nums_even[i]) {
                ans += target_even[i] - nums_even[i];
            }
        }
        for (int i=0; i<target_odd.size(); ++i) {
            if (target_odd[i] > nums_odd[i]) {
                ans += target_odd[i] - nums_odd[i];
            }
        }
        return ans / 2;
    }
};
// Time : O(nlogn)
// Space : O(n)