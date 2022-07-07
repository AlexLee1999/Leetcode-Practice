class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> table (26, -1);
        vector<int> ans;
        for (int i=0; i<s.size(); ++i) {
            table[s[i] - 'a'] = i;
        }
        int start = 0;
        int end = 0;
        for (int i=0; i<s.size(); ++i) {
            end = max(end, table[s[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)