class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        vector<int> primes_ptr(primes.size(), 1);
        for (int i=2; i<=n; ++i) {
            int min_num = INT_MAX;
            for (int j=0; j<primes.size(); ++j) {
                if (primes[j] < min_num && dp[primes_ptr[j]] < min_num) {
                    min_num = min((long long)min_num, (long long)primes[j] * (long long)dp[primes_ptr[j]]);
                }
                
            }
            dp[i] = min_num;
            for (int j=0; j<primes.size(); ++j) {
                if ((long long)primes[j] * (long long)dp[primes_ptr[j]] == min_num) {
                    primes_ptr[j]++;
                }
            }
        }
        return dp[n];
    }
};
// Time : O(np)
// Space : O(n + p)