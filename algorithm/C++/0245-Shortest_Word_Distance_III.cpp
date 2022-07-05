class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int ptr1 = -1;
        int ptr2 = -1;
        int min_dis = INT_MAX;
        if (word1 != word2) {
            for (int i = 0; i < wordsDict.size(); i++) {
                if (wordsDict[i] == word1) {
                    ptr1 = i;
                }
                if (wordsDict[i] == word2) {
                    ptr2 = i;
                }
                if (ptr1 != -1 && ptr2 != -1) {
                    min_dis = min(min_dis, abs(ptr2 - ptr1));
                }
            }
        } else {
            for (int i = 0; i < wordsDict.size(); i++) {
                if (wordsDict[i] == word1) {
                    ptr1 = i;
                    if (ptr2 != -1) {
                        min_dis = min(min_dis, abs(ptr1 - ptr2));
                    }
                    ptr2 = ptr1;
                }
            }
        }
        return min_dis;
    }
};
// Time : O(n)
// Space : O(1)