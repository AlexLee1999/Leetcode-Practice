class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        vector<int> result;
        vector<int> s_count (26, 0);
        vector<int> p_count (26, 0);
        for (int i=0; i<p_size; ++i) {
            p_count[p[i]-'a'] ++;
        }
        for (int i=0; i<s_size; ++i) {
            
            if (i >= p_size) {
                s_count[s[i-p_size]-'a'] --;
            }
            s_count[s[i]-'a'] ++;
            if (p_count == s_count) {
                result.push_back(i - p_size + 1);
            }
        }
        return result;
    }
};
// Time : O(m)
// Space : O(k)