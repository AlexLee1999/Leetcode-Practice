class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<int> table(n + 1, 0);
        vector<vector<int>> jobs (n);
        for (int i=0; i<n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        for (int i=0; i<n; ++i) {
            startTime[i] = jobs[i][0];
        }
        for (int i=n - 1; i >= 0; --i) {
            int cur_profit = 0;
            auto it = lower_bound(startTime.begin(), startTime.end(), jobs[i][1]);
            int idx = it - startTime.begin();
            if (it != startTime.end()) {
                cur_profit = jobs[i][2] + table[idx];
            } else {
                cur_profit = jobs[i][2];
            }
            if (i != n - 1) {
                table[i] = max(cur_profit, table[i + 1]); // if needed add task i
            } else {
                table[i] = cur_profit;
            }
        }
        return table[0];
    }
};
// Time : O(nlogn)
// Space : O(n)