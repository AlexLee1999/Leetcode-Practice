class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cash = 0;
        int hold = INT_MIN;
        int cash_2 = 0;
        for (int i=0; i<n; ++i) {
            int cash_1 = cash;
            cash = max(cash, hold + prices[i]);
            hold = max(hold, cash_2 - prices[i]);
            cash_2 = cash_1;
        }
        return cash;
    }
};
// Time : O(n)
// Space : O(1)