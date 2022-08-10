class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> mySet(nums.begin(), nums.end());
        int count = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (mySet.count(nums[i] + diff) && mySet.count(nums[i] + 2 * diff) ) {
                count ++;
            }
        }
        return count;
    }
};
// Time : O(n)
// Space : O(n)