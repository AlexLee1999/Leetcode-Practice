class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int last_length = 0;
        for (int i = 0; i < s.length(); ++i){
            if (s[i] == ' '){
                length = 0;
            } else {
                length ++;
                last_length = length;
            }
        }
        return last_length;
    }
};