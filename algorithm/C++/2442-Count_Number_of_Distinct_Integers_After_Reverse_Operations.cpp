class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> mySet;
        int count = 0;
        for (int i=0; i<nums.size(); ++i) {
            int p = panlindrome(nums[i]);
            mySet.insert(p);
            mySet.insert(nums[i]);
        }
        return mySet.size();
    }
    int panlindrome(int x) {
        vector<int> arr;
        while (x > 0) {
            arr.push_back(x % 10);
            x /= 10;
        }
        int ans = 0;
        for (int i=0; i < arr.size() - 1; ++i) {
            ans += arr[i];
            ans *= 10;
        }
        ans += arr.back();
        return ans;
    }
};
// Time : O(n)
// Space : O(n)