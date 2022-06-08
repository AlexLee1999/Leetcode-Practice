class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b){
            return a[0] < b[0];
        });
        vector<vector<int>> merged_result;
        merged_result.push_back(intervals[0]);
        int j = 0;
        for (int i=1; i<intervals.size(); ++i) {
            if (merged_result[j][1] < intervals[i][0]) {
                merged_result.push_back(intervals[i]);
                j ++;
            }
            else {
                merged_result[j][1] = max(intervals[i][1], merged_result[j][1]);
            }
        }
        return merged_result;
    }
};
// Time : O(nlog(n))
// Space : O(log(n)) ~ O(n)