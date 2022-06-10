class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]){
                return a[0] < b[0];
            } else {
                return a[1] < b[1];
            }
        });
        int prev = pairs[0][1];
        int count = 1;
        for (int i=1; i<pairs.size(); ++i) {
            if (pairs[i][0] > prev) {
                count ++;
                prev = pairs[i][1];
            }
        }
        return count;
    }
};
// Time : O(NlogN) greedy
// Space : O(N) 