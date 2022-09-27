class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += (nums[i] % 2 == 0) ? nums[i] : 0;
        }
        vector<int> ans(queries.size(), 0);
        for (int i=0; i<queries.size(); ++i) {
            if (((queries[i][0] + nums[queries[i][1]]) & 1) == 1 && (nums[queries[i][1]] & 1) == 1) {
                ans[i] = sum;
                nums[queries[i][1]] += queries[i][0];
            } else if (((queries[i][0] + nums[queries[i][1]]) & 1) == 0 && (nums[queries[i][1]] & 1) == 1) {
                sum += (queries[i][0] + nums[queries[i][1]]);
                ans[i] = sum;
                nums[queries[i][1]] += queries[i][0];
            } else if (((queries[i][0] + nums[queries[i][1]]) & 1) == 0 && (nums[queries[i][1]] & 1) == 0) {
                sum += (queries[i][0]);
                ans[i] = sum;
                nums[queries[i][1]] += queries[i][0];
            } else {
                sum -= (nums[queries[i][1]]);
                ans[i] = sum;
                nums[queries[i][1]] += queries[i][0];
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)