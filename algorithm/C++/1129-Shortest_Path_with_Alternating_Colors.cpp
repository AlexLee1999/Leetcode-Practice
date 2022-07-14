class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, bool>>> edge(n, vector<pair<int, bool>>());
        for (int i=0; i<redEdges.size(); ++i) {
            edge[redEdges[i][0]].push_back({redEdges[i][1], false});
        }
        for (int i=0; i<blueEdges.size(); ++i) {
            edge[blueEdges[i][0]].push_back({blueEdges[i][1], true});
        }
        
        vector<pair<int, int>> level(n, {INT_MAX, INT_MAX});
        vector<int> ans (n, 0);
        level[0].first = 0;
        level[0].second = 0;
        queue<pair<int, bool>> myQueue;
        myQueue.push({0, false});
        myQueue.push({0, true});
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                int cur = myQueue.front().first;
                bool isBlue = myQueue.front().second;
                myQueue.pop();
                for (int j=0; j<edge[cur].size(); ++j) {
                    int neighbor = edge[cur][j].first;
                    bool blue_edge = edge[cur][j].second;
                    if (!isBlue && blue_edge && level[neighbor].second > step + 1) {
                        level[neighbor].second = step + 1;
                        myQueue.push({neighbor, true});
                    }
                    if (isBlue && !blue_edge && level[neighbor].first > step + 1) {
                        level[neighbor].first = step + 1;
                        myQueue.push({neighbor, false});
                    }
                }
            }
            step ++;
        } 
        for (int i=0; i<n; ++i) {
            int min_dis = min(level[i].first, level[i].second);
            if (min_dis == INT_MAX) {
                ans[i] = -1;
            } else {
                ans[i] = min_dis;
            }
        }
        return ans;
    }
};
// Time : O(V + E)
// Space : O(V + E)
/* Idea : need to calculate shortest distance for both red and blue incoming edges */