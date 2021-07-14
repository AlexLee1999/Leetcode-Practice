class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_num = 10001;
        int max_num = -10001;
        int profit = 0;
        int n = prices.size();
        for (int i = 0; i < n; ++i) {
            if (prices[i] > max_num) {
                max_num = prices[i];
            }
            if (prices[i] < min_num) {
                min_num = prices[i];
                max_num = -10001;
            }
            profit = max(profit, max_num-min_num);
        }
        return profit;
    }
};
