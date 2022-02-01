class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int groups = n;
        vector<int> parents;
        for (int i=0; i<n; ++i) {
            parents.push_back(i);
        }
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        for (int i=0; i<logs.size(); ++i) {
            int people1 = find(logs[i][1], parents);
            int people2 = find(logs[i][2], parents);
            if (people1 != people2) {
                groups --;
                if (groups == 1) {
                    return logs[i][0];
                }
                parents[people1] = people2;
            }
        }
        return -1;
    }
    int find(int x, vector<int>& parent) {
        return parent[x] == x ? x : find(parent[x], parent);
    }
};