class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> edge(n);
        vector<int> inedge(n, 0);
        for (int i=0; i<relations.size(); ++i) {
            edge[relations[i][0]-1].push_back(relations[i][1]-1);
            inedge[relations[i][1]-1] ++;
        }
        queue<int> myQueue;
        for (int i=0; i<n; ++i) {
            if (inedge[i] == 0) {
                myQueue.push(i);
            }
        }
        int semester = 0;
        vector<int> ans;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                int course = myQueue.front();
                myQueue.pop();
                ans.push_back(course);
                for (int j=0; j<edge[course].size(); ++j) {
                    inedge[edge[course][j]] --;
                    if (inedge[edge[course][j]] == 0) {
                        myQueue.push(edge[course][j]);
                    }
                }
            }
            semester ++;
        }
        if (ans.size() != n) {
            return -1;
        }
        return semester;
    }
};