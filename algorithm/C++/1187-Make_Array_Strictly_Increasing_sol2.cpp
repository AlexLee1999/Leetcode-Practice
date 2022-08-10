class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        set<int> mySet(arr2.begin(), arr2.end());
        arr2 = vector<int>(mySet.begin(), mySet.end());
        int m = arr2.size();
        vector<vector<int>> swap(n, vector<int>(m, INT_MAX / 2));
        // swap[i][j] => min operations to keep valid by swaping arr1[i] and arr2[j];
        for (int i=0; i<m; ++i) {
            swap[0][i] = 1;
        }
        vector<int> keep(n, INT_MAX);
        // keep[i] => min operations to keep valid by keeping arr1[i];
        keep[0] = 0;
        for (int i=1; i<n; ++i) {
            int tmp_keep = INT_MAX / 2;
            int tmp_swap = INT_MAX / 2;
            for (int j=0; j<m; ++j) {
                if (j > 0) {
                    tmp_swap = min(tmp_swap, swap[i - 1][j - 1] + 1); // swap[i][j] = min(swap[i-1][k] + 1), for all k < j
                }
                if (arr1[i] > arr1[i - 1]) {
                    keep[i] = keep[i - 1];
                }
                if (arr1[i] > arr2[j]) {
                    tmp_keep = min(tmp_keep, swap[i - 1][j]);// keep[i] = min(swap[i - 1][j]) for all k < j
                }
                if (arr2[j] > arr1[i - 1]) {
                    swap[i][j] = 1 + keep[i - 1];
                }
                swap[i][j] = min(swap[i][j], tmp_swap);
                keep[i] = min(keep[i], tmp_keep);
            }
        }
        int ans = *min_element(swap.back().begin(), swap.back().end());
        ans = min(keep.back(), ans);
        if (ans == INT_MAX / 2) {
            return -1;
        }
        return ans;
    }
};
// Time : O(mn)
// Space : O(mn)