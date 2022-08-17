class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<vector<char>> table(numRows);
        int idx = 0;
        bool dir = true;
        for (int i=0; i<s.size(); ++i) {
            if (dir) {
                table[idx].push_back(s[i]);
                if (idx >= numRows - 1) {
                    dir = false;
                    idx --;
                } else {
                    idx ++;
                }
            } else {
                table[idx].push_back(s[i]);
                if (idx <= 0) {
                    dir = true;
                    idx ++;
                } else {
                    idx --;
                }
            }
        }
        string ans = "";
        for (int i=0; i<numRows; ++i) {
            for (int j=0; j<table[i].size(); ++j) {
                ans += table[i][j];
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)