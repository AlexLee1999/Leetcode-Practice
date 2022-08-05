class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> myMap;
        stack<string> myStack;
        vector<string> ans;
        for (int i=0; i<tickets.size(); ++i) {
            myMap[tickets[i][0]].insert(tickets[i][1]);
        }
        dfs("JFK", myMap, ans);
        return ans;
    }
    void dfs(string cur, unordered_map<string, multiset<string>>& myMap, vector<string>& ans) {
        while (!myMap[cur].empty()) {
            string next = *myMap[cur].begin();
            myMap[cur].erase(myMap[cur].begin());
            dfs(next, myMap, ans);
        }
        ans.insert(ans.begin(), cur);
    }
};
// Time : O(E)
// Space : O(V + E)