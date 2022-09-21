class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candles;
        vector<int> ans(queries.size());
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '|') {
                plates.push_back(i);
            }
        }
        for (int i=0; i<queries.size(); ++i) {
            int low = lower_bound(candles.begin(), candles.end(), queries[i][0]) - candles.begin();
            int high = upper_bound(candles.begin(), candles.end(), queries[i][1]) - candles.begin();
            high --;
            if (high > low) {
                ans[i] = candles[high] - candles[low] - (high - low);
            }
        }
        return ans;
    }
};
// Time : O(qlogn + n)
// Space : O(n)