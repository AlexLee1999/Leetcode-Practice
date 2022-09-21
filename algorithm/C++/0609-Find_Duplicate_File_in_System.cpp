class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> myMap;
        for (int i=0; i<paths.size(); ++i) {
            int pos = 0;
            for (int j=0; j<paths[i].size(); ++j) {
                if (paths[i][j] == ' ') {
                    pos = j;
                    break;
                }
            }
            string dirs = paths[i].substr(0,  pos);
            int prev = pos + 1;
            vector<string> files;
            for (int j=pos + 1; j < paths[i].size(); ++j) {
                if (paths[i][j] == ' ') {
                    files.push_back(paths[i].substr(prev,  j - prev));
                    prev = j + 1;
                }
            }
            files.push_back(paths[i].substr(prev));
            for (int j=0; j<files.size(); ++j) {
                pair<string, string> file = getFiles(files[j]);
                string fullDir = dirs + '/' + file.first;
                myMap[file.second].push_back(fullDir);
            }
        }
        vector<vector<string>> ans;
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            if (it->second.size() > 1) {
                ans.push_back({});
                for (int i=0; i<it->second.size(); ++i) {
                    ans.back().push_back(it->second[i]);
                }
            }
        }
        return ans;
    }
    pair<string, string> getFiles(string& s) {
        pair<string, string> ans = {"", ""};
        int pos = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                ans.first = s.substr(0, i);
                pos = i;
            }
            if (s[i] == ')') {
                ans.second = s.substr(pos + 1, i - pos);
            }
        }
        return ans;
    }
};
// Time : O(nk)
// Space : O(nk)