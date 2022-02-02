class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_size = s1.size();
        int s2_size = s2.size();
        vector<int> s1_count(26, 0);
        vector<int> s2_count(26, 0);
        for (int i=0; i<s1_size; ++i) {
            s1_count[s1[i] - 'a'] ++;
        }
        for (int i=0; i<s2_size; ++i) {
            s2_count[s2[i] - 'a'] ++;
            if (i >= s1_size) {
                s2_count[s2[i-s1_size] - 'a'] --;
            }
            if (s1_count == s2_count) {
                return true;
            }
        }
        return false;
    }
};