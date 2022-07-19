class Solution {
public:
    int numTilings(int n) {
        long f_2 = 1;
        long f_1 = 2;
        long p_1 = 1;
        int MOD = 1e9 + 7;
        if (n < 3) {
            return n;
        }
        for (int i=3; i<=n; ++i) {
            long tmp = f_1;
            long f = (f_1 + f_2 + 2 * p_1) % MOD;
            long p = (p_1 + f_2) % MOD;
            f_2 = tmp;
            f_1 = f;
            p_1 = p;
        }
        return f_1 % MOD;
    }
};
// Time : O(n)
// Space : O(1)
/* Idea : f(k) is where k is fully covered, p(k) is where k is partially covered 
f(k) = f(k - 1) + f(k - 2) + 2 * p(k - 1)
There, f(k - 1) => add vertical, f(k - 2) => add horizontal, p(k - 1) => add tromino (there are two ways of tromino)

p(k) = f(k - 2) + p(k - 1)
f(k - 2) => add a tromino, p(k - 1) => add horizonal
*/