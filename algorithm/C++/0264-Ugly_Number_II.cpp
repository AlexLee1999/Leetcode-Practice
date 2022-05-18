class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        int ptr2 = 1;
        int ptr3 = 1;
        int ptr5 = 1;
        for (int i=2; i<=n; ++i) {
            dp[i] = min(2*dp[ptr2], min(3*dp[ptr3], 5*dp[ptr5]));
            if (dp[i] == 2*dp[ptr2]) {
                ptr2 ++;
            } 
            if (dp[i] == 3*dp[ptr3]) { //2*3 == 3*2 move both pointers 
                ptr3 ++;
            }
            if (dp[i] == 5*dp[ptr5]) {
                ptr5 ++;
            }
        }
        return dp[n];
    }
};