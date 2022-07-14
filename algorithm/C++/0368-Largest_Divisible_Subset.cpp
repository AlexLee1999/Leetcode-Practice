class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> myMap;
        for (int i=0; i<n; ++i) {
            myMap[nums[i]].push_back(nums[i]);
        }
        for (int i=0; i<n; ++i) {
            for (int j=i + 1; j<n; ++j) {
                if ((nums[j] % nums[i]) == 0 && myMap[nums[i]].size() + 1 > myMap[nums[j]].size()) {
                    myMap[nums[j]] = myMap[nums[i]];
                    myMap[nums[j]].push_back(nums[j]);
                }
            }
        }
        vector<int> ans;
        for (auto it=myMap.begin(); it != myMap.end(); ++it) {
            if (it->second.size() > ans.size()) {
                ans = it->second;
            }
        }
        return ans;
    }
};
// Time : O(n^2)
// Space : O(n^2)