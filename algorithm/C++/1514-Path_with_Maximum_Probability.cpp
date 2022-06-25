class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> myHeap;
        vector<vector<pair<int, double>>> edge(n, vector<pair<int, double>>());
        for (int i=0; i<edges.size(); ++i) {
            double w = (succProb[i]);
            edge[edges[i][0]].emplace_back(edges[i][1], w);
            edge[edges[i][1]].emplace_back(edges[i][0], w);
            
        }
        vector<bool> visited(n, false);
        vector<double> dist(n, 0);
        myHeap.push({1, start});
        dist[start] = 1;
        while (!myHeap.empty()) {
            pair<double, int> top = myHeap.top();
            myHeap.pop();
            if (visited[top.second]) {
                continue;
            }
            visited[top.second] = true;
            
            for (int i=0; i<edge[top.second].size(); ++i) {
                int neighbor = edge[top.second][i].first;
                double weight = edge[top.second][i].second;
                if (!visited[neighbor] && dist[neighbor] < top.first * weight) {
                    myHeap.push({top.first * weight, neighbor});
                    dist[neighbor] = top.first * weight;
                }
            }
        }
        return dist[end];
    }
};
// Time : O(ElogV)
// Space : O(V + E)