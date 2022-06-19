class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int len = words[0].size();
        unordered_map<string, int> myMap;
        for (int i=0; i<words.size(); ++i) {
            myMap[words[i]] ++;
        }
        vector<int> result;
        for (int i=0; i<len; ++i) {
            unordered_map<string, int> found;
            int start = i;
            for (int j=i; j < n - len + 1; j += len) {
                string current = s.substr(j, len);
                if (myMap.find(current) != myMap.end()) {
                    found[current] ++;
                    while (found[current] > myMap[current]) {
                        if (found.find(s.substr(start, len)) != found.end()) {
                            found[s.substr(start, len)] --;
                        }
                        start += len;
                    }
                    int length = (j - start + len);
                    if (length == words.size() * len) {
                        result.push_back(start);
                    }
                } else {
                    found.clear();
                    start = j + len;
                }
            }
        }
        return result;
    }
};