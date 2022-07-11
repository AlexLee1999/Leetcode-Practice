class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> token;
        int ptr = 0;
        for (int i=0; i<=sentence.size(); ++i) {
            if (i == sentence.size()) {
                token.push_back(sentence.substr(ptr, i - ptr));
            } else {
                if (sentence[i] == ' ') {
                    token.push_back(sentence.substr(ptr, i - ptr));
                    ptr = i + 1;
                }
            }
        }
        toGoat(token[0],  1);
        string s = token[0];
        for (int i=1; i<token.size(); ++i) {
            toGoat(token[i], i + 1);
            s += " ";
            s += token[i];
        }
        return s;
    }
    void toGoat(string& s, int idx) {
        if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' || s[0] == 'A' || s[0] == 'E' || s[0] == 'I' || s[0] == 'O' || s[0] == 'U') {
            s += "ma";
        } else {
            char first = s[0];
            s = s.substr(1);
            s += first;
            s += "ma";
        }
        for (int i=0; i<idx; ++i) {
            s += 'a';
        }
    }
};
// Time : O(n)
// Space : O(n)