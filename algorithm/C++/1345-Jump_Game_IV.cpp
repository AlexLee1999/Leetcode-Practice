class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> myMap;
        for (int i=0; i<arr.size(); ++i) {
            myMap[arr[i]].push_back(i);
        }
        
        queue<int> myQueue;
        myQueue.push(0);
        int step = 0;
        visited[0] = true;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                int front = myQueue.front();
                if (front == n-1) {
                    return step;
                }
                myQueue.pop();
                for (int j=0; j<myMap[arr[front]].size(); ++j) {
                    if (!visited[myMap[arr[front]][j]]) {
                        myQueue.push(myMap[arr[front]][j]);
                        visited[myMap[arr[front]][j]] = true;
                    }
                }
                myMap.erase(arr[front]);
                if (front + 1 < n && !visited[front + 1]) {
                    myQueue.push(front + 1);
                    visited[front + 1] = true;
                }
                if (front - 1 >= 0 && !visited[front - 1]) {
                    myQueue.push(front - 1);
                    visited[front - 1] = true;
                }
            }
            step ++;
        }
        return -1;
    }
};