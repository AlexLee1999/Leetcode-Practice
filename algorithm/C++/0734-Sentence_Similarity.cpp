class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        
        unordered_map<string, unordered_set<string>> myMap;
        for (int i=0; i<similarPairs.size(); ++i) {
            myMap[similarPairs[i][0]].insert(similarPairs[i][1]);
            myMap[similarPairs[i][1]].insert(similarPairs[i][0]);
        }
        for (int i=0; i<sentence1.size(); ++i) {
            if (myMap[sentence2[i]].count(sentence1[i]) || myMap[sentence1[i]].count(sentence2[i]) || sentence1[i] == sentence2[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
// Time : O(n + P) P = pairs.size()
// Space : O(P)