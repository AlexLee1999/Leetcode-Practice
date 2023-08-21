class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26, -1);
        int start = 0;
        int count = 1;
        for (int i=0; i<s.size(); ++i) {
            if (lastSeen[s[i] - 'a'] >= start) {
                start = i;
                count ++;
            } 
            lastSeen[s[i] - 'a'] = i;
        }
        return count;
    }
};