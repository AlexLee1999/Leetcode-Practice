class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        // unordered_map<int, unordered_map<int, long long>> myMap;
        vector<vector<long long>> myMap(4000, vector<long long>(k + 1, 0));
        int mod = 1e9 + 7;
        int min_pos = startPos;
        int max_pos = startPos;
        myMap[startPos + 2000][0] = 1;
        for (int i=0; i<k; ++i) {
            for (int j=max(min_pos, endPos - (k - i)); j <= min(max_pos, endPos + (k - i)); ++j) {
                int pos = j;
                myMap[pos + 1 + 2000][i + 1] += myMap[pos + 2000][i];
                myMap[pos - 1 + 2000][i + 1] += myMap[pos + 2000][i];
                myMap[pos + 1 + 2000][i + 1] %= mod;
                myMap[pos - 1 + 2000][i + 1] %= mod;
            }
            min_pos --;
            max_pos ++;
        }
        return myMap[endPos + 2000][k];
    }
};
// Time : O(nk)
// Space : O(nk)