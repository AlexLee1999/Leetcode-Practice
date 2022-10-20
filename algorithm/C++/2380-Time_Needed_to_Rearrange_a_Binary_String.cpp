class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        bool flag = false;
        int step = 0;
        while (!flag) {
            flag = true;
            int i = 1;
            while (i < s.size()){
                if (s[i] == '1' && s[i - 1] == '0') {
                    s[i] = '0';
                    s[i - 1] = '1';
                    i += 2;
                    flag = false;
                } else {
                    i ++;
                }
            }
            step ++;
        }
        return step - 1;
    }
};
// Time : O(n)
// Space : O(1)