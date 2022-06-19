class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        
        queue<int> myQueue;
        myQueue.push(start);
        visited[start] = true;
        
        while(!myQueue.empty()) {
            int front = myQueue.front();
            myQueue.pop();
            if (arr[front] == 0) {
                return true;
            }
            if (front + arr[front] < n && !visited[front + arr[front]]) {
                myQueue.push(front + arr[front]);
                visited[front + arr[front]] = true;
            }
            if (front - arr[front] >= 0 && !visited[front - arr[front]]) {
                myQueue.push(front - arr[front]);
                visited[front - arr[front]] = true;
            }
        }
        return false;
    }
};
// Time : O(n)
// Space : O(n)