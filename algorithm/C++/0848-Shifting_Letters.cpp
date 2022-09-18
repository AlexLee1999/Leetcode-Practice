class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for (int i=shifts.size() - 2; i >= 0; --i) {
            shifts[i] += shifts[i + 1];
            shifts[i] %= 26;
        }
        string ans = "";
        for (int i=0; i<s.size(); ++i) {
            int num = s[i] - 'a';
            num += shifts[i];
            num %= 26;
            ans += num + 'a';
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)