class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        vector<int> prefix(words.size(), 0);
        vector<string> ans(words.size(), "");
        for (int i = 0; i<words.size(); ++i) {
            ans[i] = Abbreviation(words[i], 0);
        }
        
        for (int i = 0; i<words.size(); ++i) {
            while (true) {
                unordered_set<int> mySet;
                for (int j= i + 1; j < words.size(); ++j) {
                    if (ans[i] == ans[j]) {
                        mySet.insert(j);
                    }
                }
                if (mySet.size() == 0) {
                    break;
                }
                mySet.insert(i);
                for (auto it = mySet.begin(); it != mySet.end(); ++it) {
                    prefix[*it] ++;
                    ans[*it] = Abbreviation(words[*it], prefix[*it]);
                }
            }
        } 
        return ans;
    }
    string Abbreviation(string& s, int i) {
        if (s.size() - i <= 3) {
            return s;
        }
        return s.substr(0, i + 1) + to_string(s.size() - i - 2) + s[s.size() - 1];
    }
};
// Time : O(N^2)
// Space : O(N)
// where N is the number of characters across all words in the given array