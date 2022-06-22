class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int num = 0;
        if (ruleKey == "type") {
            for (int i=0; i<items.size(); ++i) {
                if(items[i][0] == ruleValue) {
                    num ++;
                }
            }
        }
        if (ruleKey == "color") {
            for (int i=0; i<items.size(); ++i) {
                if(items[i][1] == ruleValue) {
                    num ++;
                }
            }
        }
        if (ruleKey == "name") {
            for (int i=0; i<items.size(); ++i) {
                if(items[i][2] == ruleValue) {
                    num ++;
                }
            }
        }
        return num;
    }
};
// Time : O(n)
// Space : O(1)