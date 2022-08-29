class Solution {
public:
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, unordered_map<string, double>> edge;
        for (int i=0; i<equations.size(); ++i) {
            if (!edge[equations[i][0]].count(equations[i][1]) && !edge[equations[i][1]].count(equations[i][0])) {
                edge[equations[i][0]][equations[i][1]] = values[i];
                edge[equations[i][1]][equations[i][0]] = 1.0 / values[i];
            } else {
                if (edge[equations[i][0]][equations[i][1]] != values[i] || edge[equations[i][1]][equations[i][0]] != 1.0 / values[i]) {
                    return true;
                }
            }
            
        }
        for (int i=0; i<equations.size(); ++i) {
            double val = values[i];
            edge[equations[i][0]].erase(equations[i][1]);
            edge[equations[i][1]].erase(equations[i][0]);
            double ans = BFS(edge, equations[i][0], equations[i][1]);
            if (ans != 1/double(0) && abs(val / ans - 1) > 1e-5) {
                return true;
            }
            edge[equations[i][0]][equations[i][1]] = values[i];
            edge[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        return false;
    }
    double BFS(unordered_map<string, unordered_map<string, double>>& edge, string& start, string& end) {
        queue<pair<string, double>> myQueue;
        myQueue.push({start, 1.0});
        unordered_set<string> visited;
        visited.insert(start);
        while (!myQueue.empty()) {
            pair<string, double> front = myQueue.front();
            myQueue.pop();
            if (front.first == end) {
                return front.second;
            }
            for (auto it = edge[front.first].begin(); it != edge[front.first].end(); ++it) {
                if (!visited.count(it->first)) {
                    visited.insert(it->first);
                    myQueue.push({it->first, it->second * front.second});
                }
            }
        }
        return 1/double(0);
    }
};
// Time : O(ve)
// Space : O(ve)