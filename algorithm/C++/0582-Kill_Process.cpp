class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> myMap;
        for (int i=0; i<pid.size(); ++i) {
            myMap[ppid[i]].push_back(pid[i]);
        }
        queue<int> myQueue;
        vector<int> ans;
        myQueue.push(kill);
        while(!myQueue.empty()) {
            int process = myQueue.front();
            myQueue.pop();
            ans.push_back(process);
            for (int i=0; i<myMap[process].size(); ++i) {
                myQueue.push(myMap[process][i]);
            }
        }
        return ans;
    }
};