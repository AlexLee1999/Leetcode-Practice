class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int max_num = SHRT_MIN;
        int min_num = SHRT_MAX;
        for (int i=0; i<n; ++i) {
            if (prices[i] > max_num) {
                max_num = prices[i];
            }
            if (prices[i] < min_num) {
                min_num = prices[i];
                max_num = SHRT_MIN;
            }
            ans = max(ans, (max_num-min_num));
            
        }
        return ans;
    }
};