class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> colorSet(3);
        vector<int> ans (queries.size(), -1);
        for (int i=0; i<colors.size(); ++i) {
            colorSet[colors[i] - 1].push_back(i);
        }
        for (int i=0; i<queries.size(); ++i) {
            if (!colorSet[queries[i][1] - 1].empty()) {
                ans[i] = binarySearch(colorSet[queries[i][1] - 1], queries[i][0]);
            }
        }
        return ans;
    }
    int binarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        int min_diff = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return 0;
            }
            min_diff = min(min_diff, abs(arr[mid] - target));
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return min_diff;
    }
};
// Time : O(n + Qlogn)
// Space : O(n)