class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> visited_front(forbidden.begin(), forbidden.end());
        unordered_set<int> visited_back(forbidden.begin(), forbidden.end());
        queue<pair<int, bool>> myQueue;
        myQueue.push({0, false});
        if (visited_front.count(0)) {
            return -1;
        }
        visited_front.insert(0);
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                pair<int, bool> front = myQueue.front();
                myQueue.pop();
                int pos = front.first;
                if (pos < 0 || pos > 10000) {
                    continue;
                }
                if (pos == x) {
                    return step;
                }
                bool back = front.second;
                
                if (!back && !visited_back.count(pos - b) && pos - b >= 0) {
                    myQueue.push({pos - b, true});
                    visited_back.insert(pos - b);
                }
                if (!visited_front.count(pos + a)) {
                    myQueue.push({pos + a, false});
                    visited_front.insert(pos + a);
                }
            }
            step ++;
        }
        return -1;
    }
};
// Time : O(maxDis)
// Space : O(maxDis)