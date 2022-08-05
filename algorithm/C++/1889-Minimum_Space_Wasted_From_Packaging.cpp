class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        long long min_box = 1e11;
        int mod = 1e9 + 7;
        sort(packages.begin(), packages.end());
        long long total_sum = 0;
        for (int i=0; i<packages.size(); ++i) {
            total_sum += packages[i];
        }
        for (int i=0; i<boxes.size(); ++i) {
            sort(boxes[i].begin(), boxes[i].end());
            min_box = min(min_box, countBox(packages, boxes[i]));
        }
        return min_box == 1e11 ? -1 : (min_box - total_sum) % mod;
        
    }
    long long countBox(vector<int>& packages, vector<int>& boxes) {
        long long count = 0;
        if (packages.back() > boxes.back()) {
            return 1e11;
        }
        long long prev = 0;
        for (int i=0; i<boxes.size(); ++i) {
            auto it = upper_bound(packages.begin(), packages.end(), boxes[i]);
            long long idx = it - packages.begin();
            count += (idx - prev) * boxes[i];
            prev = idx;
        }
        return count;
    }
};
// Time : O(nlogn + mlogm + nlogm)
// Space : O(1)