class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int i = 1;
        while (i < words.size()) {
            if (isAnagrams(words[i], words[i - 1])) {
                words.erase(words.begin() + i);
            } else {
                i ++;
            }
        }
        return words;
    }
    bool isAnagrams(string& a, string& b) {
        if (a.size() != b.size()) {
            return false;
        }
        vector<int> table_a(26, 0);
        vector<int> table_b(26, 0);
        for (int i=0; i<a.size(); ++i) {
            table_a[a[i] - 'a'] ++;
        }
        for (int i=0; i<b.size(); ++i) {
            table_b[b[i] - 'a'] ++;
        }
        return table_a == table_b;
    }
};
// Time : O(nk)
// Space : O(n)