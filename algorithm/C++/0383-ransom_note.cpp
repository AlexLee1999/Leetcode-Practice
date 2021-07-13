class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> table (26, 0);
        for(int i=0; i<magazine.length(); ++i){
            table[magazine[i]-'a']++;
        }
        for(int j=0; j<ransomNote.length(); ++j){
            table[ransomNote[j]-'a']--;
            if(table[ransomNote[j]-'a']<0){
                return false;
            }
        }
        return true;
    }
};
