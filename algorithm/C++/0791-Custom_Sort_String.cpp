class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> myMap;
        for (int i=0; i<s.size(); ++i) {
            myMap[s[i]] ++;
        }
        string ans = "";
        for (int i=0; i<order.size(); ++i) {
            if (!myMap.count(order[i])) {
                continue;
            }
            while (myMap[order[i]] > 0) {
                ans += order[i];
                myMap[order[i]] --;
            }
        }
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            for (int i=0; i<it->second; ++i) {
                ans += it->first;
            }
        }
        return ans;
    }
};
// Time : O(n + m)
// Space : O(n)