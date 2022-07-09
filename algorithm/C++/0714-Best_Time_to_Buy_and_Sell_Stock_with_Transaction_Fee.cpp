class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int cash = 0;
        int hold = INT_MIN / 2;
        for (int i=0; i<n; ++i) {
            int cash_1 = cash;
            cash = max(cash, (hold + prices[i] - fee));
            hold = max(hold, cash_1 - prices[i]);
        }
        return cash;
    }
};
// Time : O(n)
// Space : O(1)