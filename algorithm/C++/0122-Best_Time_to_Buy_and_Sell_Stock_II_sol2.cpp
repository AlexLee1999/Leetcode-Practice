class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int hold = INT_MIN;
        int cash = 0;
        for(int i=0; i<n; ++i){
            int cash_1 = cash;
            cash = max(cash, hold + prices[i]);
            hold = max(hold, cash_1 - prices[i]);
        }
        return cash;
    }
};
// Time : O(n)
// Space : O(1)