class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        unordered_map<int, vector<int>> myMap;
        int m = targetGrid.size();
        int n = targetGrid[0].size();
        unordered_map<int, unordered_set<int>> edge;
        unordered_map<int, int> indegree;
        int num_color = 0;
        for (int i=0; i<targetGrid.size(); ++i) {
            for (int j=0; j<targetGrid[0].size(); ++j) {
                int color = targetGrid[i][j];
                if (myMap.find(color) == myMap.end()) {
                    myMap[color] = {{INT_MAX, INT_MIN, INT_MAX, INT_MIN}};
                    indegree[color] = 0;
                    num_color ++;
                }
                myMap[color][0] = min(myMap[color][0], i);
                myMap[color][1] = max(myMap[color][1], i);
                myMap[color][2] = min(myMap[color][2], j);
                myMap[color][3] = max(myMap[color][3], j);
            }
        }
        
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            for (int i=it->second[0]; i<=it->second[1]; ++i) {
                for (int j=it->second[2]; j <= it->second[3]; ++j) {
                    if (targetGrid[i][j] != it->first) {
                        if (edge[it->first].count(targetGrid[i][j]) == 0){
                            edge[it->first].insert(targetGrid[i][j]);
                            indegree[targetGrid[i][j]] ++;
                        }
                    }
                }
            }
        }
        
        queue<int> myQueue;
        for (auto it = indegree.begin(); it != indegree.end(); ++it) {
            if (it->second == 0) {
                myQueue.push(it->first);
            }
        }
        int color_count = 0;
        while (!myQueue.empty()) {
            int front = myQueue.front();
            myQueue.pop();
            color_count ++;
            for (auto it = edge[front].begin(); it!= edge[front].end(); ++it) {
                indegree[*it] --;
                if (indegree[*it] == 0) {
                    myQueue.push(*it);
                }
            }
        }
        return color_count == num_color;
    }
};