/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        for (int i = 0, count = 0; i < 30 && count < 6; ++i) {
            string word = words[words.size()/2];
            count = master.guess(word);
            vector<string> newList;
            for (int j=0; j<words.size(); ++j) {
                if (match(words[j], word) == count) {
                    newList.push_back(words[j]);
                }
            }
            words = newList;
        }
    }
    int match(string& word, string& target) {
        int count = 0;
        for (int i=0; i<word.size(); ++i) {
            if (word[i] == target[i]) {
                count ++;
            }
        }
        return count;
    }
};