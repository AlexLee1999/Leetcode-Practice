class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<pair<int, int>>> edge(n, vector<pair<int, int>>());
        for (int i=0; i<n; ++i) {
            if (manager[i] != -1) {
                edge[manager[i]].push_back({i, informTime[manager[i]]});
            }
        }
        vector<int> dest (n, INT_MAX);
        dest[headID] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myHeap;
        myHeap.push({0, headID});
        while (!myHeap.empty()) {
            int cur_node = myHeap.top().second;
            int cur_time = myHeap.top().first;
            myHeap.pop();
            if (dest[cur_node] < cur_time) {
                continue;
            }
            for (int i=0; i<edge[cur_node].size(); ++i) {
                int neighbor = edge[cur_node][i].first;
                int time = edge[cur_node][i].second;
                if (dest[neighbor] > time + cur_time) {
                    dest[neighbor] = time + cur_time;
                    myHeap.push({dest[neighbor], neighbor});
                }
            }
        }
        int max_time = 0;
        for (int i=0; i<n; ++i) {
            max_time = max(max_time, dest[i]);
        }
        return max_time;
    }
};
// Time : O(Elogn)
// Space : O(n + E)