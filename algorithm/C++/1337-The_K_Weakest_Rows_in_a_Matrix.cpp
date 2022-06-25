class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> arr;
        for (int i=0; i<mat.size(); ++i) {
            arr.emplace_back(accumulate(mat[i].begin(), mat[i].end(), 0), i);
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (int i=0; i<k; ++i) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
// Time : O(n + mlogm)
// Space : O(m)