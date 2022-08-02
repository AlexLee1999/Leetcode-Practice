class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> myHeap;
        for (int i=0; i<n; ++i) {
            myHeap.push({matrix[i][0], {i, 0}});
        }
        for (int i=0; i<k; ++i) {
            pair<int, pair<int, int>> tmp = myHeap.top();
            if (i == k-1) {
                return tmp.first;
            } 
            myHeap.pop();
            if (tmp.second.second + 1 < n) {
                myHeap.push({matrix[tmp.second.first][tmp.second.second + 1], {tmp.second.first, tmp.second.second + 1}});
            }
        }
        return -1;
    }
};
// Time : O(n + klogn)
// Space : O(n^2)