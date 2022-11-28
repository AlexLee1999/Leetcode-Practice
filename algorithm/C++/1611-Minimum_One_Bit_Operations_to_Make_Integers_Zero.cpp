class Solution {
public:
    int minimumOneBitOperations(int n) {
        for(int i=1; i<32; i *= 2) {
            n ^= n >> i;
        }
        return n;
    }
};
// Time : O(1)
// Space : O(1)