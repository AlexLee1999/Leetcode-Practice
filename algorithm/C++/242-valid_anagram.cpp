class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> table (26, 0);
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0; i<s.length(); ++i){
            table[(int)s[i] - (int)'a']++;
            table[(int)t[i] - (int)'a']--;
        }
        for(int i=0; i<26; ++i){
            if(table[i]!=0){
                return false;
            }
        }
        return true;
    }
};
