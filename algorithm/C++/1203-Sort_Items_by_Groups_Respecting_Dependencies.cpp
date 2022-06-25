class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int index = m;
        for(int i=0; i<group.size(); ++i) {
            if (group[i] == -1) {
                group[i] = index;
                index ++;
            }
        }
        int group_count = index;
        vector<vector<int>> groups(group_count, vector<int>());
        for(int i=0; i<n; ++i) {
            groups[group[i]].push_back(i);
        }
        vector<int> indegreegroup(group_count, 0);
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for (int i=0; i<beforeItems.size(); ++i) {
            for (int j=0; j<beforeItems[i].size(); ++j) {
                graph[beforeItems[i][j]].push_back(i);
                indegree[i] ++;
                if (group[i] != group[beforeItems[i][j]]) {
                    indegreegroup[group[i]] ++;  // build graph between groups using beforeItems
                }
            }
        }
        queue<int> mygroupQueue;
        vector<int> ans;
        for (int i=0; i<indegreegroup.size(); ++i) {
            if (indegreegroup[i] == 0) {
                mygroupQueue.push(i);
            }
        }
        while (!mygroupQueue.empty()) {
            int front = mygroupQueue.front();
            mygroupQueue.pop();
            
            
            queue<int> myitemQueue;
            for (int i=0; i<groups[front].size(); ++i) {
                if (indegree[groups[front][i]] == 0) {
                    myitemQueue.push(groups[front][i]);
                }
            }
            while(!myitemQueue.empty()) {
                int item = myitemQueue.front();
                myitemQueue.pop();
                ans.push_back(item);
                for (int i=0; i<graph[item].size(); ++i) {
                    int neighbor = graph[item][i];
                    indegree[neighbor] --;
                    if (group[neighbor] != front) {
                        indegreegroup[group[neighbor]] --;
                        if (indegreegroup[group[neighbor]] == 0) {
                            mygroupQueue.push(group[neighbor]);
                        }
                    } else {
                        if (indegree[neighbor] == 0) {
                            myitemQueue.push(neighbor);
                        }
                    }
                }
            }
        }
        if (ans.size() < n - 1) {
            return vector<int> {};
        }
        return ans;
    }
};
// Time : O(V + E) E is the edge(items in groups and beforeitems)
// Space : O(V + E)