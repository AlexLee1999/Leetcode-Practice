class Solution {
public:
    int countOdds(int low, int high) {
        if (low % 2 == 0) {
            low ++;
        } 
        if (high % 2 == 0) {
            high --;
        }
        if (low > high) {
            return 0;
        }
        return (high - low + 1 + 1) / 2;
    }
};
// Time : O(1)
// Space : O(1)