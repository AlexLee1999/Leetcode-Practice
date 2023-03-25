class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edge(n, vector<int>());
        for (int i=0; i<edges.size(); ++i) {
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> scc_list;
        unordered_set<int> visited;
        for (int i=0; i<n; ++i) {
            if (visited.count(i)) {
                continue;
            }
            int component_size = 0;
            visited.insert(i);
            queue<int> myQueue;
            myQueue.push(i);
            while (!myQueue.empty()) {
                int tmp = myQueue.front();
                myQueue.pop();
                component_size ++;
                for (int j=0; j<edge[tmp].size(); ++j) {
                    if (visited.count(edge[tmp][j])) {
                        continue;
                    }
                    myQueue.push(edge[tmp][j]);
                    visited.insert(edge[tmp][j]);
                }
            }
            scc_list.push_back(component_size);
        }
        long long ans = (long long)n * (long long)(n - 1) / 2;
        for (int i=0; i<scc_list.size(); ++i) {
            ans -= ((long long)scc_list[i] * (long long)(scc_list[i] - 1)) / 2;
        }
        return ans;
    }
};