class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_gap = arr[1] - arr[0];
        vector<vector<int>> ans;
        for (int i=0; i<arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] == min_gap) {
                ans.push_back({arr[i], arr[i + 1]});
            } else if (arr[i + 1] - arr[i] < min_gap) {
                ans.clear();
                ans.push_back({arr[i], arr[i + 1]});
                min_gap = arr[i + 1] - arr[i];
            }
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(1)