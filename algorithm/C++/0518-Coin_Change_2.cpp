class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> table(amount + 1, 0);
        table[0] = 1;
        
        for (int j=0; j<coins.size(); ++j) { // add one coin each time
            for (int i=coins[j]; i<=amount; ++i) {
                table[i] += table[i - coins[j]];
            }
        }
        return table[amount];
    }
};
// Time : O(Tn)
// Space : O(T) T is the amount of money