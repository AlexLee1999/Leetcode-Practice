class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int count = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                open ++;
            } else if (s[i] == ')' && open > 0) {
                open --;
            } else {
                count ++;
            }
        }
        return count + open;
    }
};
// Time : O(n)
// Space : O(1)