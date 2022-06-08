class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> table(26, 0);
        int left = 0;
        int right = 0;
        int max_freq = 0;
        int max_len = 0;
        for (right = 0; right < s.size(); ++right) {
            table[s[right] - 'A'] ++;
            if (table[s[right] - 'A'] > max_freq) {
                max_freq = table[s[right] - 'A'];
            }
            while (right - left + 1 - max_freq > k) { //will only exectute once in every for-loop, so the max_freq don't need to be updated everytime
                table[s[left] - 'A'] --;
                left ++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
// Time : O(n)
// Space : O(1)