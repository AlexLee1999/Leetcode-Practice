class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i=0; i<tasks.size(); ++i) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0]; 
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myHeap;
        long long time = 0;
        int i = 0;
        vector<int> ans;
        while (i < tasks.size() || !myHeap.empty()) {
            if (myHeap.empty()) {
                time = max(time, (long long)tasks[i][0]);
            }
            while (i < tasks.size() && time >= tasks[i][0]) {
                myHeap.push({tasks[i][1], tasks[i][2]});
                i ++;
            }
            pair<int, int> top = myHeap.top();
            myHeap.pop();
            time += top.first;
            ans.push_back(top.second);
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(n)