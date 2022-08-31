class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> myMap;
        vector<vector<string>> ans;
        for (int i=0; i<strings.size(); ++i) {
            string transformed = transform(strings[i]);
            myMap[transformed].push_back(strings[i]);
        }
        for (auto it=myMap.begin(); it != myMap.end(); ++it) {
            ans.push_back(it->second);
        }
        return ans;
    }
    string transform(string s) {
        int shift = s[0] - 'a';
        for (int i=0; i<s.size(); ++i) {
            s[i] = (s[i] - shift);
            if (s[i] < 'a') {
                s[i] += 26;
            } 
        }
        return s;
    }
};
// Time : O(nk)
// Space : O(nk)