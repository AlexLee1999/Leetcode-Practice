class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int word1_ptr = 0;
        int word2_ptr = 0;
        string s = "";
        while (word1_ptr < word1.size() && word2_ptr < word2.size()) {
            s += word1[word1_ptr];
            word1_ptr ++;
            s += word2[word2_ptr];
            word2_ptr ++;
        }
        while (word1_ptr < word1.size()) {
            s += word1[word1_ptr];
            word1_ptr ++;
        }
        while (word2_ptr < word2.size()) {
            s += word2[word2_ptr];
            word2_ptr ++;
        }
        return s;
    }
};
// Time : O(m + n)
// Space : O(1)