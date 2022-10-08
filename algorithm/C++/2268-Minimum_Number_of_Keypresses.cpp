class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> count(26, 0);
        for (int i=0; i<s.size(); ++i) {
            count[s[i] - 'a'] ++;
        }
        sort(count.begin(), count.end(), greater<int>());
        int ans = 0;
        for (int i=0; i<26; ++i) {
            if (i < 9) {
                ans += count[i];
            } else if (i < 18) {
                ans += count[i] * 2;
            } else {
                ans += count[i] * 3;
            }
        }
        return ans;
        
    }
};
// Time : O(n)
// Space : O(1)