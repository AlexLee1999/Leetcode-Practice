class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int wptr1 = 0;
        int wptr2 = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        while (ptr1 < word1.size() && ptr2 < word2.size()) {
            if (word1[ptr1][wptr1] == word2[ptr2][wptr2]) {
                wptr1 ++;
                wptr2 ++;
                if (wptr1 == word1[ptr1].size()) {
                    wptr1 = 0;
                    ptr1 ++;
                }
                if (wptr2 == word2[ptr2].size()) {
                    wptr2 = 0;
                    ptr2 ++;
                }
            } else {
                return false;
            }
        }
        if (ptr1 != word1.size()) {
            return false;
        }
        if (ptr2 != word2.size()) {
            return false;
        }
        return true;
    }
};
// Time : O(n)
// Space : O(1)