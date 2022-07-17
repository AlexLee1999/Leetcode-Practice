class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> Q1;
        queue<int> Q2;
        for (int i=1; i<=n; ++i) {
            Q1.push(i);
        }
        for (int i=0; i<n-1; ++i) {
            for (int j=0; j<k-1; ++j) {
                int front = Q1.front();
                Q1.pop();
                Q1.push(front);
            }
            Q1.pop();
        }
        return Q1.front();
    }
};
// Time : O(nk)
// Space : O(n)