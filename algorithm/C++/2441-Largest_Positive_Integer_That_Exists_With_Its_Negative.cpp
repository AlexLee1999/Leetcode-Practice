class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> mySet(nums.begin(), nums.end());
        for (auto it=mySet.begin(); it != mySet.end(); ++it) {
            if (*it > 0 && mySet.count(-1 * (*it))) {
                ans = max(*it, ans);
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)