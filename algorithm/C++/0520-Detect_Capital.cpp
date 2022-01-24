class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstCapital = false;
        bool hasCapital = false;
        bool hasLower = false;
        for (int i=0; i<word.size(); ++i) {
            if (i == 0 && isupper(word[i])) {
                firstCapital = true;
                continue;
            }
            if (i != 0 && isupper(word[i]) && !firstCapital) { //aBC
                return false;
            }
            if (i != 0 && isupper(word[i]) && firstCapital && !hasCapital && !hasLower) {
                hasCapital = true;
                continue;
            }
            if (i != 0 && !isupper(word[i]) && firstCapital && !hasCapital && !hasLower) {
                hasLower = true;
                continue;
            }
            if (i != 0 && !isupper(word[i]) && firstCapital && hasCapital) { //LEet
                return false;
            }
            if (i != 0 && isupper(word[i]) && firstCapital && hasLower) { //LeET
                return false;
            }
        }
        return true;
    }
};