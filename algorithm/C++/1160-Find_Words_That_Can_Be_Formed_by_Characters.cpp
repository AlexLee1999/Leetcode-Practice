class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> count(26, 0);
        for (int i=0; i<chars.size(); ++i) {
            count[chars[i] - 'a'] ++;
        }
        int ans = 0;
        for (int i=0; i<words.size(); ++i) {
            if (isValid(words[i], count)) {
                ans += words[i].size();
            }
        }
        return ans;
    }
    bool isValid(string words, vector<int> count) {
        for (int i=0; i<words.size(); ++i) {
            count[words[i] - 'a']--;
            if (count[words[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(nk)
// Space : O(n)