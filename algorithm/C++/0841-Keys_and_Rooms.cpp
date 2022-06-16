class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> myStack;
        int n = rooms.size();
        vector<int> visited(n, false);
        visited[0] = true;
        myStack.push(0);
        while (!myStack.empty()) {
            int top = myStack.top();
            myStack.pop();
            
            for (int i=0; i<rooms[top].size(); ++i) {
                if (!visited[rooms[top][i]]) {
                    myStack.push(rooms[top][i]);
                    visited[rooms[top][i]] = true;
                }
            }
        }
        for (int i=0; i<n; ++i) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }
};