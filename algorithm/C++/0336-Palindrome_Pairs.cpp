class Trie {
public:
    Trie() {
        wordID = -1;
    }
private:
    int wordID;
    unordered_map<char, Trie*> child;
    vector<int> palindromeRemaining;
    friend class Solution;
};
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie* trie = new Trie();
        for (int i=0; i<words.size(); ++i) {
            Trie* ptr = trie;
            string reverse_word = words[i];
            if (words[i] != "") {
                reverse(reverse_word.begin(), reverse_word.end());
            }
            for (int j=0; j < reverse_word.size(); ++j) {
                if (hasPalindrome(reverse_word, j)) {
                    ptr->palindromeRemaining.push_back(i);
                }
                char ch = reverse_word[j];
                if (!ptr->child.count(ch)) {
                    ptr->child[ch] = new Trie();
                }
                ptr = ptr->child[ch];
            }
            ptr->wordID = i;
        }
        
        vector<vector<int>> ans;
        for (int i=0; i<words.size(); ++i) {
            Trie* ptr = trie;
            for (int j=0; j<words[i].size(); ++j) {
                if (ptr->wordID != -1 && hasPalindrome(words[i], j)) {
                    ans.push_back({i, ptr->wordID});
                }
                char ch = words[i][j];
                ptr = ptr->child[ch];
                if (ptr == nullptr) {
                    break;
                }
            }
            if (ptr == nullptr) {
                continue;
            }
            if (ptr->wordID != -1 && ptr->wordID != i) {
                ans.push_back({i, ptr->wordID});
            }
            for (int k=0; k<ptr->palindromeRemaining.size(); ++k) {
                ans.push_back({i, ptr->palindromeRemaining[k]});
            }
        }
        return ans;
    }
    bool hasPalindrome(string& s, int idx) {
        int left = idx;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                left ++;
                right --;
            } else {
                return false;
            }
        }
        return true;
    }
};
// Time : O(k^n)