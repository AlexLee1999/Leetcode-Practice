class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myHeap;
        sort(events.begin(), events.end());
        int max_day = 0;
        for (int i=0; i<events.size(); ++i) {
            max_day = max(max_day, events[i][1]);
        }
        int event = 0;
        int ptr = 0;
        for (int i=1; i<=max_day; ++i) {
            while (ptr < events.size() && events[ptr][0] <= i) {
                myHeap.push({events[ptr][1], events[ptr][0]});
                ptr ++;
            }
            while (!myHeap.empty() && myHeap.top().first < i) {
                myHeap.pop();
            }
            if (!myHeap.empty() && myHeap.top().first >= i) {
                myHeap.pop();
                event++;
            }
        }
        return event;
    }
};
// Time : O(nlogn)
// Space : O(n)