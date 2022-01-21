class Solution {
public:
    int numSquares(int n) {
        queue<int> myQueue;
        unordered_set<int> mySet;
        myQueue.push(0);
        int depth = 0;
        while (!myQueue.empty()) {
            depth ++;
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                int front = myQueue.front();
                myQueue.pop();
                int result = 0;
                for (int j=1; j<n; ++j) {
                    result = (front + j * j); //try to add square numbers
                    if (result > n) {
                        break;
                    } else if (result == n) {
                        return depth;
                    } else {
                        if (mySet.count(result) == 0) {
                            mySet.insert(result); // insert current sums of square
                            myQueue.push(result); // enter the current result 
                        }
                    }
                }
            }
        }
        return depth;
    }
};