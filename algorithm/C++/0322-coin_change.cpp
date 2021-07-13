class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> table(amount+1, 10001);
        table[0] = 0;
        for (int i=1; i<=amount; ++i){
            for(int j=0; j<n; ++j){
                if(coins[j]<=i){
                    table[i] = min(1+table[i-coins[j]], table[i]);
                }
            }
        }
        return table[amount] == 10001 ? -1: table[amount];
    }
};
