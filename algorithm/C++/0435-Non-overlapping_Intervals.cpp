class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        int n = intervals.size();
        int prev_end = 0; //latest interval index
        int count = 0;
        for (int i=1; i<n; ++i) {
            if (intervals[i][0] < intervals[prev_end][1]) {
                if (intervals[i][1] < intervals[prev_end][1]) { 
                    // if the later ends early, change the previous to the later to create more space 
                    prev_end = i;
                }
                count ++;
            } else {
                //if non overlapping, add the interval and change the end interval
                prev_end = i; 
            }
        }
        return count;
    }
};
// Time : O(nlogn)
// Space : O(1)