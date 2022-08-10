class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> table(n + 1, 0);
        for (int i = n - 1; i>=0; --i) {
            table[i] = stoneValue[i] - table[i + 1];
            if (i + 1 < n) {
                table[i] = max(table[i], stoneValue[i] + stoneValue[i + 1] - table[i + 2]);
            }
            if (i + 2 < n) {
                table[i] = max(table[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - table[i + 3]);
            }
        }
        if (table[0] > 0) {
            return "Alice";
        } else if (table[0] < 0) {
            return "Bob";
        }
        return "Tie";
    }
};
// Time : O(n)
// Space : O(n)