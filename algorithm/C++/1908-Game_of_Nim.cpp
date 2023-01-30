class Solution {
public:
    bool nimGame(vector<int>& piles) {
        int sum = 0;
        for (int i=0; i<piles.size(); ++i) {
            sum ^= piles[i];
        }
        return sum != 0;
    }
};