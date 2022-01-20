class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        int count = 0;
        while (count < intervals.size() && intervals[count][1] < newInterval[0]) {
                res.push_back(intervals[count]);
                count++;
        }
        while (count < intervals.size() && intervals[count][1] >= newInterval[0] && intervals[count][0] <= newInterval[1]) {
                newInterval[0] = min(intervals[count][0], newInterval[0]);
                newInterval[1] = max(intervals[count][1], newInterval[1]);
                count++;
        }
        res.push_back(newInterval);
        while (count < intervals.size() && intervals[count][0] > newInterval[1]) {
                res.push_back(intervals[count]);
                count++;
        }
        return res;
    }
};
