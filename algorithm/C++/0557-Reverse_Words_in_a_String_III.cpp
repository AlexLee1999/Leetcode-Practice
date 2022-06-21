class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        int prev = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == ' ') {
                string substr = s.substr(prev, i-prev);
                reverse(substr.begin(), substr.end());
                arr.push_back(substr);
                prev = i + 1;
            }
        }
        string substr = s.substr(prev, s.size()-prev);
        reverse(substr.begin(), substr.end());
        arr.push_back(substr);
        string res = "";
        for (int i=0; i<arr.size()-1; ++i) {
            res += arr[i];
            res += " ";
        }
        return res + arr[arr.size() - 1];
    }
};
// Time : O(n)
// Space : O(n)