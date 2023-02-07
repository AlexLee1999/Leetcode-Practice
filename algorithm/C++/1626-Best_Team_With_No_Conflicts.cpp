class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> arr;
        int n = scores.size();
        vector<int> table(n, 0);
        for (int i=0; i<n; ++i) {
            arr.push_back({ages[i], scores[i]});
        }
        
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i=0; i<n; ++i) {
            table[i] = arr[i].second;
            ans = max(ans, table[i]);
        }
        
        for (int i=1; i<n; ++i) {
            for (int j=i - 1; j>= 0; --j) {
                if (arr[i].second >= arr[j].second) {
                    table[i] = max(table[i], table[j] + arr[i].second);
                }
            }
            ans = max(ans, table[i]);
        }
        return ans;
    }
};
// Time : O(n^2)
// Space : O(n)