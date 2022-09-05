class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> mySet(nums.begin(), nums.end());
        if (mySet.count(0)) {
            return mySet.size() - 1;
        }
        return mySet.size();
    }
};
// Time : O(n)
// Space : O(n)