class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> myMap;
        for (int i=0; i<tasks.size(); ++i) {
            myMap[tasks[i]] ++;
        }
        int ans = 0;
        for (auto it=myMap.begin(); it != myMap.end(); ++it) {
            if (it->second == 1) {
                return -1;
            } else if (it->second % 3 == 0) {
                ans += it->second / 3;
            } else if (it->second % 3 == 1) {
                ans += it->second / 3;
                ans ++;
            } else {
                ans += it->second / 3;
                ans ++;
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)