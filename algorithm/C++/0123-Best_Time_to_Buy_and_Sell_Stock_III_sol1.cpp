class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> right(n + 1, 0);
        vector<int> left(n, 0);
        int min_price = prices[0];
        int max_price = prices[n-1];
        int max_profit = 0;
        for (int i=1; i<n; ++i) {
            left[i] = max(left[i-1], prices[i] - min_price); //sell at day i
            min_price = min(min_price, prices[i]);
        }
        for (int i=n-2; i>0; --i) {
            right[i] = max(right[i+1], max_price - prices[i]); // buy at day i
            max_price = max(max_price, prices[i]);
        }
        for (int i=0; i<n; ++i) {
            max_profit = max(max_profit, right[i+1] + left[i]);
        }
        return max_profit;
    }
};
// Time : O(n)
// Space : O(n)