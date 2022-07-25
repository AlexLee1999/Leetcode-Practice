class Solution {
public:
    int twoEggDrop(int n) {
        int K = 2;
        vector<vector<int>> table(n + 1, vector<int>(K + 1, 0));
        int moves = 0;
        while (table[moves][K] < n) {
            moves ++;
            for (int k = 1; k<=K; ++k) {
                table[moves][k] = table[moves - 1][k] + table[moves - 1][k - 1] + 1;
                // table[moves][k] is the highest floor can be determined
            }
        }
        return moves;
    }
};
// Time : O(nk)
// Space : O(nk)