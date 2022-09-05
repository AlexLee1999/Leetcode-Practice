class Solution {
public:
    int largestVariance(string s) {
        vector<int> count(26, 0);
        for (int i=0; i<s.size(); ++i) {
            count[s[i] - 'a'] ++;
        }
        int ans = 0;
        for (int i=0; i<26; ++i) {
            for (int j=0; j<26; ++j) {
                if (i == j || count[i] == 0 || count[j] == 0) {
                    continue;
                }
                int counti = 0;
                int countj = 0;
                int remainj = count[j];
                for (int k=0; k<s.size(); ++k) {
                    if (s[k] - 'a' != i && s[k] - 'a' != j) {
                        continue;
                    }
                    if (s[k] - 'a' == i) {
                        counti ++;
                    }
                    if (s[k] - 'a' == j) {
                        countj ++;
                        remainj --;
                    }
                    if (counti > countj && countj > 0) {
                        ans = max(ans, counti - countj);
                    }
                    if (counti < countj && remainj > 0) { // if remain j <= 0, there will be no valid substring 
                        counti = 0;
                        countj = 0;
                    }
                }
                
            }
        }
        return ans;
    }
};
// Time : O(26*26n)
// Space : O(26)