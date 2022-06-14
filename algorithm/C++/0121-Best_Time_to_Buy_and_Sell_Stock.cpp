class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int min_num = SHRT_MAX;
        for (int i=0; i<n; ++i) {
            if (prices[i] < min_num) {
                min_num = prices[i];
            } else if (prices[i] - min_num > ans) {
                ans = (prices[i] - min_num);
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)