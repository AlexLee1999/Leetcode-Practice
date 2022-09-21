class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> table(60, 0);
        for (int i=0; i<time.size(); ++i) {
            table[time[i] % 60] ++;
        }
        int ans = 0;
        for (int i=1; i<=29; ++i) {
            ans += table[i] * table[60-i];
        }
        ans += table[30] * (table[30] - 1) / 2;
        ans += (long)table[0] * (long)(table[0] - 1) / 2;
        return ans;
    }
};
// Time : O(n)
// Space : O(n)