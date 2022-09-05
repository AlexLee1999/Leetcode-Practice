class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        int max_range = 9;
        int min_range = 1;
        for (int i=0; i<n-1; ++i) {
            min_range *= 10;
        }
        for (int i=0; i<n-1; ++i) {
            max_range *= 10;
            max_range += 9;
        }
        queue<int> myQueue;
        for (int i=1; i<=9; ++i) {
            myQueue.push(i);
        }
        while (!myQueue.empty()) {
            int front = myQueue.front();
            myQueue.pop();
            if (min_range <= front && front <= max_range) {
                ans.push_back(front);
                continue;
            }
            if (k > 0) {
                if (front % 10 - k >= 0) {
                    myQueue.push(front * 10 + front % 10 - k);
                }
                if (front % 10 + k < 10) {
                    myQueue.push(front * 10 + front % 10 + k);
                }
            } else {
                myQueue.push(front * 10 + front % 10);
            }
            
        }
        return ans;
    }
};
// Time : O(2^N)
// Space : O(2^N)