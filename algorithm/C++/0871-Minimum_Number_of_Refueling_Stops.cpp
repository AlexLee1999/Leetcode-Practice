class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long long> table(n + 1, 0); // table[i] = longest distance using i gas station 
        table[0] = startFuel;
        for (int i=0; i<n; ++i) {
            for (int j=i; j>= 0; --j) {
                if (table[j] >= stations[i][0]) {// Update the distance when adding station i
                    table[j + 1] = max(table[j + 1], table[j] + stations[i][1]);
                }
            }
        }
        for (int i=0; i<=n; ++i) {
            if (table[i] >= target) {
                return i;
            }
        }
        return -1;
    }
};
// Time : O(n^2)
// Space : O(n)