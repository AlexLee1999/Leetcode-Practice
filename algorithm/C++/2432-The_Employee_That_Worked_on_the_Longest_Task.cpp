class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int prev = 0;
        int max_time = 0;
        vector<int> candidate;
        for (int i=0; i<logs.size(); ++i) {
            int time = logs[i][1] - prev;
            prev = logs[i][1];
            if (max_time == time) {
                candidate.push_back(logs[i][0]);
            }
            if (max_time < time) {
                max_time = time;
                candidate.clear();
                candidate.push_back(logs[i][0]);
            }
        }
        int ans = *min_element(candidate.begin(), candidate.end());
        return ans;
    }
};
// Time : O(n)
// Space : O(n)