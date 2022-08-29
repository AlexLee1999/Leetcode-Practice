class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> edge;
        vector<double> ans(queries.size(), -1.0);
        for (int i=0; i<equations.size(); ++i) {
            edge[equations[i][0]].push_back({equations[i][1], values[i]});
            edge[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        for (int i=0; i<queries.size(); ++i) {
            if (!edge.count(queries[i][0]) || !edge.count(queries[i][1])) {
                continue;
            }
            if (queries[i][0] == queries[i][1]) {
                ans[i] = 1.0;
                continue;
            }
            ans[i] = BFS(queries[i][0], queries[i][1], edge);
        }
        return ans;
    }
    double BFS(string& start, string& end, unordered_map<string, vector<pair<string, double>>>& edge) {
        queue<pair<string, double>> myQueue;
        unordered_map<string, bool> visited;
        myQueue.push({start, 1.0});
        visited[start] = true;
        while (!myQueue.empty()) {
            pair<string, double> front = myQueue.front();
            myQueue.pop();
            if (front.first == end) {
                edge[start].push_back({end, front.second});
                edge[end].push_back({start, 1.0 / front.second});
                return front.second;
            }
            for (int i=0; i<edge[front.first].size(); ++i) {
                string neighbor = edge[front.first][i].first;
                if (!visited[neighbor]) {
                    myQueue.push({neighbor, front.second * edge[front.first][i].second});
                    visited[neighbor] = true;
                }
            }
        }
        return -1.0;
    }
};
// Time : O(qn)
// Space : O(qn)