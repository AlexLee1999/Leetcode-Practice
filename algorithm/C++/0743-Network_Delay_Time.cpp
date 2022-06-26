class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> edge(n + 1, vector<pair<int, int>>());
        for (int i=0; i<times.size(); ++i) {
            edge[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        vector<int> duration(n + 1, INT_MAX);
        priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> myHeap;
        
        duration[k] = 0;
        myHeap.push({0, k});
        while(!myHeap.empty()) {
            pair<int, int> front = myHeap.top();
            myHeap.pop();
            int cur_time = front.first;
            int cur_node = front.second;
            if (duration[cur_node] < cur_time) {
                continue;
            }
            for (int i=0; i<edge[cur_node].size(); ++i) {
                int neighbor = edge[cur_node][i].first;
                int dist = edge[cur_node][i].second;
                
                if (duration[neighbor] > dist + cur_time) {
                    duration[neighbor] = dist + cur_time;
                    myHeap.push({dist + cur_time, neighbor});
                }
            }
        }
        int time = INT_MIN;
        for (int i=1; i<=n; ++i) {
            time = max(time, duration[i]);
        }
        if (time == INT_MAX) {
            return -1;
        }
        return time;
    }
};
// Time : O(Elogn)
// Space : O(n + E)