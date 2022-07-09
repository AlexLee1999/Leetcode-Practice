class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cash = 0; // the amount of money in ith day 
        int hold = INT_MIN; // the amount of money in ith day holding stock
        for (int i=0; i<n; ++i) {
            cash = max(cash, hold + prices[i]); // hold is the i-1th day 
            hold = max(hold, -prices[i]); // update the hold from i-1th to ith day
        }
        return cash;
    }
};
// Time : O(n)
// Space : O(1)