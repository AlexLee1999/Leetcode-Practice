class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> myMap;
        for (int i=0; i<s.size(); ++i) {
            if (myMap.find(s[i]) == myMap.end()) {
                myMap[s[i]] = {i, i};
            } else {
                myMap[s[i]][1] = max(myMap[s[i]][1], i);
            }
        }
        vector<int> ans;
        vector<vector<int>> interval;
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            interval.push_back((it->second));
        }
        sort(interval.begin(), interval.end());
        int prev_start = interval[0][0];
        int prev_end = interval[0][1];
        for (int i=1; i<interval.size(); ++i) {
            if (prev_end < interval[i][0]) {
                ans.push_back(prev_end - prev_start + 1);
                prev_start = interval[i][0];
                prev_end = interval[i][1];
            } else {
                prev_end = max(prev_end, interval[i][1]);
            }
        }
        ans.push_back(prev_end - prev_start + 1);
        return ans;
    }
};
// Time : O(n + klogk)
// Space : O(k)