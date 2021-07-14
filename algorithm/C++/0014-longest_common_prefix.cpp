class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string retS = "";
        for (int i = 0; i<strs[0].length(); ++i) {
            for (int j = 1; j<strs.size(); ++j) {
                if (i >= strs[j].length()) {
                    return retS;
                }
                if (strs[j][i] != strs[0][i]) {
                    return retS;
                }
            }
            retS += strs[0][i];
        }
        return retS;
    }
};
