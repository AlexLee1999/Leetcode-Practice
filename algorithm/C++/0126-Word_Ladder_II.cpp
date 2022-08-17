class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> cur = {beginWord};
        unordered_set<string> total(wordList.begin(), wordList.end());
        total.erase(beginWord);
        unordered_map<string, unordered_set<string>> myMap;
        while (!cur.empty() && !myMap.count(endWord)) {
            unordered_set<string> nxt;
            for (auto it = cur.begin(); it != cur.end(); ++it) {
                string tmp = *it;
                for (int i = 0; i < tmp.length(); i++) {
                    string s = tmp;
                    for (char j = 'a'; j <= 'z'; j++) {
                        s[i] = j;
                        if (total.count(s)) {
                            myMap[s].insert(tmp);
                            nxt.insert(s);
                        }
                    }
                }
            }
            for (auto it = nxt.begin(); it != nxt.end(); ++it) {
                total.erase(*it);
            }
            cur = nxt;
        }
        vector<string> cur_lst = {endWord};
        backtrack(cur_lst, beginWord, myMap, ans);
        return ans;
    }
private:
    void backtrack(vector<string>& cur, string& beginWord, unordered_map<string, unordered_set<string>>& myMap, vector<vector<string>>& ans) {
        if (cur.back() == beginWord) {
            ans.push_back({cur.rbegin(), cur.rend()});
            return;
        }
        string tmp = cur.back();
        for (auto it=myMap[tmp].begin(); it != myMap[tmp].end(); ++it) {
            cur.push_back(*it);
            backtrack(cur, beginWord, myMap, ans);
            cur.pop_back();
        }
    }
};