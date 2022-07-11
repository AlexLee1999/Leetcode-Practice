class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) {
            return vector<string>();
        }
        int h = 0;
        int pow_const = pow(4, 10);
        unordered_set<int> seen;
        set<string> res;
        for (int i=0; i<10; ++i) {
            h = h * 4 + toInt(s[i]);
        }
        seen.insert(h);
        for (int i=1; i<s.size() - 9; ++i) {
            h = h * 4 - toInt(s[i - 1]) * pow_const + toInt(s[i + 9]);
            if (seen.count(h)) {
                res.insert(s.substr(i, 10));
            }
            seen.insert(h);
        }
        return vector<string>(res.begin(), res.end());
    }
    int toInt(char c) {
        if (c == 'A') {
            return 0;
        } else if (c == 'C') {
            return 1;
        } else if (c == 'G') {
            return 2;
        }
        return 3;
    }
};
// Time : O(N-L)
// Space : O(L)