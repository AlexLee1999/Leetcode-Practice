class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cash_with_1 = 0;
        int cash_with_2 = 0;
        int hold_1 = INT_MIN;
        int hold_2 = INT_MIN;
        for (int i=0; i<n; ++i) {
            cash_with_2 = max(cash_with_2, hold_2 + prices[i]);
            hold_2 = max(hold_2, cash_with_1 - prices[i]);
            cash_with_1 = max(cash_with_1, hold_1 + prices[i]);
            hold_1 = max(hold_1, -prices[i]);
        }
        return cash_with_2;
    }
};
// Time : O(n)
// Space : O(1)