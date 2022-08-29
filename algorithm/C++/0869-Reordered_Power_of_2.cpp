class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> count(10, 0);
        while (n > 0) {
            count[n % 10] ++;
            n /= 10;
        }
        for (int i=0; i<31; ++i) {
            vector<int> res = findDigits(i);
            if (res == count) {
                return true;
            }
        }
        return false;
    }
    vector<int> findDigits(int pow) {
        vector<int> count(10, 0);
        int n = 1;
        for (int i=1; i<=pow; ++i) {
            n *= 2;
        }
        while (n > 0) {
            count[n % 10] ++;
            n /= 10;
        }
        return count;
    }
};
// Time : O(log^2n)