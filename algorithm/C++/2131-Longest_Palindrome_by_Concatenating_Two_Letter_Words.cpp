class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> count(26, vector<int>(26, 0));
        int ans = 0;
        for (int i=0; i<words.size(); ++i) {
            int first = words[i][0] - 'a';
            int second = words[i][1] - 'a';
            if (count[second][first]) {
                ans += 4;
                count[second][first] --;
            } else {
                count[first][second] ++;
            }
        }
        for (int i=0; i<26; ++i) {
            if (count[i][i]) { // if there are odd numbers
                return ans + 2;
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)