class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i=0; i<words.size(); ++i) {
            string s = words[i];
            if (s.size() > words.size()) {
                return false;
            }
            for (int j=0; j<s.size(); ++j) {
                
                if (words[j].size() <= i) {
                    return false;
                }
                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};