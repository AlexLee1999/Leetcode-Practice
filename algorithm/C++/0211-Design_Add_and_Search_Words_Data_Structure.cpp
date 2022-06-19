class TrieNode {
public:
    TrieNode() {
        for (int i=0; i<26; ++i) {
            children[i] = nullptr; // using Vector will cause TLE
        }
        isEnd = false;
    }
private:
    TrieNode* children[26];
    bool isEnd;
    friend class WordDictionary;
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (int i=0; i<word.size(); ++i) {
            if (node->children[word[i] - 'a'] == nullptr) {
                node->children[word[i] - 'a'] = new TrieNode();
            } 
            node = node->children[word[i] - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return searchSubWord(word, root);
    }
private:
    bool searchSubWord(string word, TrieNode* node) {
        for (int i=0; i<word.size(); ++i) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; ++j) {
                    if (node->children[j] != nullptr) {
                        if (searchSubWord(word.substr(i + 1), node->children[j])) {
                            return true;
                        } 
                    }
                }
                return false;
            } else if (node->children[word[i] - 'a'] == nullptr){
                return false;
            } else {
                node = node->children[word[i] - 'a'];
            }    
        }
        return node->isEnd;
    }
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */