class Solution {
public:
    string reverseWords(string s) {
        int prev = 0;
        vector<string> arr;
        int ptr = 0;
        while (ptr < s.size()) {
            if (s[ptr] != ' ') {
                ptr ++;
            } else {
                if (ptr > prev) { // if ptr and prev has word
                    arr.push_back(s.substr(prev, ptr - prev));
                    ptr ++;
                    prev = ptr;
                } else { // if ptr and prev has no word
                    ptr ++;
                    prev ++;
                }
            }
        }
        if (ptr > prev) {
            arr.push_back(s.substr(prev, ptr - prev));
        }
        reverse(arr.begin(), arr.end());
        string ans = arr[0];
        for (int i=1; i<arr.size(); ++i) {
            ans += " ";
            ans += arr[i];
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)