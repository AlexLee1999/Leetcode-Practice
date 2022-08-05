class Solution {
public:
    string freqAlphabets(string s) {
        int i = 0;
        string ans = "";
        while (i < s.size()) {
            if (i < s.size() - 2 && s[i + 2] == '#') {
                ans += (char)(stoi(s.substr(i, 2)) + 'a' - 1);
                i += 3;
            } else {
                ans += (char)(stoi(s.substr(i, 1)) + 'a' - 1); 
                i += 1;
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)