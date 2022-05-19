class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses);
        vector<int> inedge(numCourses, 0);
        for (int i=0; i<prerequisites.size(); ++i) {
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inedge[prerequisites[i][0]] ++;
        }
        queue<int> myQueue;
        for (int i=0; i<numCourses; ++i) {
            if (inedge[i] == 0) {
                myQueue.push(i);
            }
        }
        vector<int> ans;
        while (!myQueue.empty()) {
            int course = myQueue.front();
            myQueue.pop();
            ans.push_back(course);
            for (int i=0; i<edge[course].size(); ++i) {
                inedge[edge[course][i]] --;
                if (inedge[edge[course][i]] == 0) {
                    myQueue.push(edge[course][i]);
                }
            }
        }
        if (ans.size() != numCourses) {
            ans.clear();
            return ans;
        }
        return ans;
    }
};