class Solution {
public:
    vector<string> tokenizeString(string s) {
        vector<string> results;
        string word = "";
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == ' ') {
                results.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }
        if (word != "") {
            results.push_back(word);
        }
        
        return results;
    }
    bool wordPattern(string pattern, string s) {
        vector<string> str_vector = tokenizeString(s);
        unordered_map<char, string> myMap;        
        unordered_map<string, char> myStringMap;
        if (str_vector.size() != pattern.size()) {
            return false;
        }
        for (int i=0; i<pattern.size(); ++i) {
            if (myMap.find(pattern[i]) == myMap.end() && myStringMap.find(str_vector[i]) == myStringMap.end()) {
                myMap[pattern[i]] = str_vector[i];                
                myStringMap[str_vector[i]] = pattern[i];
            } else {
                if (myMap[pattern[i]] != str_vector[i] || myStringMap[str_vector[i]] != pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};