class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) {
            return true;
        }
        vector<vector<int>> edge(numCourses);
        vector<int> inedge(numCourses, 0);
        for (int i=0; i<prerequisites.size(); ++i) {
            if (prerequisites[i][0] == prerequisites[i][1]) {
                return false;
            }
            edge[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inedge[prerequisites[i][1]] ++;
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
        return ans.size() == numCourses;
    }
};