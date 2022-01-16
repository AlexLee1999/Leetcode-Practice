class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>> myHeap;
        myHeap.push(intervals[0][1]);
        for (int i=1; i<intervals.size(); ++i) {
            if (myHeap.top() <= intervals[i][0]) {
                myHeap.pop();
            }
            myHeap.push(intervals[i][1]);
        }
        return myHeap.size();
    }
};