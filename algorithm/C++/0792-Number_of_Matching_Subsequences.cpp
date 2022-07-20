class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> myMap;
        int count = 0;
        for (int i=0; i<s.size(); ++i) {
            myMap[s[i]].push_back(i);
        }
        for (int i=0; i<words.size(); ++i) {
            int pos = -1;
            int isSubsequence = true;
            for (int j=0; j<words[i].size(); ++j) {
                auto it = upper_bound(myMap[words[i][j]].begin(), myMap[words[i][j]].end(), pos);
                // Find the index of char words[i][j] that is greater than pos
                if (it == myMap[words[i][j]].end()) {
                    isSubsequence = false;
                    break;
                } else {
                    pos = *it;
                }
            }
            if (isSubsequence) {
                count ++;
            }
        }
        return count;
    }
};
// Time : O(S + W * L * log(S))
// Space : O(S)
// S is the length of s
// W is the number of words
// L is the length of words