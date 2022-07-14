class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        vector<int> dirs = {jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity};
        
        if (jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }
        
        queue<int> myQueue;
        myQueue.push(0);
        unordered_set<int> visited;
        visited.insert(0);
        while (!myQueue.empty()) {
            int front = myQueue.front();
            myQueue.pop();
            if (front == targetCapacity) {
                return true;
            }
            if (front < 0 || front > jug1Capacity + jug2Capacity) {
                continue;
            }
            for (int i=0; i<4; ++i) {
                int next = front + dirs[i];
                if (!visited.count(next)) {
                    myQueue.push(next);
                    visited.insert(next);
                }
            }
        }
        return false;
    }
};