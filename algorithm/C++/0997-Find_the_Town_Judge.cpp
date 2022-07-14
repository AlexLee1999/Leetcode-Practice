class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> totaldegree(n + 1, 0);
        for (int i=0; i<trust.size(); ++i) {
            totaldegree[trust[i][1]] ++;
            totaldegree[trust[i][0]] --;
        }
        for (int i=1; i<=n; ++i) {
            if (totaldegree[i] == n - 1) {
                return i;
            }
        } 
        return -1;
    }
};
// Time : O(n)
// Space : O(n)