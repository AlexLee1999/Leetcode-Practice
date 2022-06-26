class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> myHeap;
        
        vector<vector<pair<int, int>>> edge (n, vector<pair<int, int>>());
        for (int i=0; i<edges.size(); ++i) {
            edge[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            edge[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        myHeap.push({passingFees[0], {0, 0}});
        while (!myHeap.empty()) {
            int node = myHeap.top().second.first;
            int fee = myHeap.top().first;
            int time = myHeap.top().second.second;
            myHeap.pop();
            
            if (node == n - 1) {
                return fee;
            }
            for (int i=0; i<edge[node].size(); ++i) {
                int neighbor = edge[node][i].first;
                int travel_time = edge[node][i].second;
                if (time + travel_time > maxTime) {
                    continue;
                }
                if (dist[neighbor] > time + travel_time) {
                    dist[neighbor] = time + travel_time;
                    myHeap.push({fee + passingFees[neighbor], {neighbor, time + travel_time}});
                }
            }
        }
        return -1;
    }
};
// Time : O(Elogn)
// Space : O(n + E)