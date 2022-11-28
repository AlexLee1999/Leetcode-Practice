class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> myMap(n);
        int ans = 0;
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                long long d = (long long)nums[i] - (long long)nums[j];
                int sum = 0;
                if (myMap[j].count(d)) {
                    sum = myMap[j][d];
                }
                myMap[i][d] += sum + 1;
                ans += sum;
            }
        }
        return ans;
    }
};
// Time : O(n^2)
// Space : O(n^2)