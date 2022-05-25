class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> seq;
        for (int i=0; i<n; ++i) {
            auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
            if (it == seq.end()) {
                seq.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return seq.size() >= 3;
    }
};