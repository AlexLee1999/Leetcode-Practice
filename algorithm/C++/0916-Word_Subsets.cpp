class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> table(26, 0);
        vector<string> ans;
        for (int i=0; i<words2.size(); ++i) {
            vector<int> table_each_word(26, 0);
            for (int j=0; j<words2[i].size(); ++j) {
                table_each_word[words2[i][j] - 'a'] ++;
                table[words2[i][j] - 'a'] = max(table[words2[i][j] - 'a'], table_each_word[words2[i][j] - 'a']);
            }
        }
        for (int i=0; i<words1.size(); ++i) {
            vector<int> table_each_word(26, 0);
            for (int j=0; j<words1[i].size(); ++j) {
                table_each_word[words1[i][j] - 'a'] ++;
            }
            if (isSubset(table, table_each_word)) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
    bool isSubset(vector<int>& table, vector<int>& table_each_word) {
        for (int i=0; i<26; ++i) {
            if (table_each_word[i] < table[i]) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(A + B)
// Space : O(A + B)