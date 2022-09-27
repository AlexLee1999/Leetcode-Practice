class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MAX);
        if (dominoes[n - 1] == 'L') {
            left[n - 1] = 0;
        }
        for (int i=n - 2; i>=0; --i) {
            if (dominoes[i] == 'L') {
                left[i] = 0;
            } else if (dominoes[i] == '.' && left[i + 1] != INT_MAX) {
                left[i] = left[i + 1] + 1;
            }
        }
        if (dominoes[0] == 'R') {
            right[0] = 0;
        }
        for (int i=1; i<n; ++i) {
            if (dominoes[i] == 'R') {
                right[i] = 0;
            } else if (dominoes[i] == '.' && right[i - 1] != INT_MAX) {
                right[i] = right[i - 1] + 1;
            }
        }
        string ans = "";
        for (int i=0; i<n; ++i) {
            if (right[i] == left[i]) {
                ans += '.';
            } else if (right[i] < left[i]) {
                ans += 'R';
            } else {
                ans += 'L';
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)