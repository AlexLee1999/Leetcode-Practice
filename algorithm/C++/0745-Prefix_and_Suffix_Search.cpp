class TrieNode {
public:
    TrieNode() {
        children = vector<TrieNode*>(27, nullptr);
        idx = 0;
    }
    void setIndex(int i) {
        idx = i;
    }
private:
    vector<TrieNode*> children;
    int idx;
    friend class WordFilter;
};
class WordFilter {
public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        for (int i=0; i<words.size(); ++i) {
            for (int j=0; j<=words[i].size(); ++j) {
                TrieNode* node = root;
                node->setIndex(i);
                string word = words[i].substr(j) + '{' + words[i];
                for (int k=0; k<word.size(); ++k) {
                    if (node->children[word[k] - 'a'] == nullptr) {
                        node->children[word[k] - 'a'] = new TrieNode();
                        node = node->children[word[k] - 'a'];
                        node->setIndex(i);
                    } else{
                        node = node->children[word[k] - 'a'];
                        node->setIndex(i);
                    }
                }
                
            }
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* node = root;
        string word = suffix + '{' + prefix;
        for (int i=0; i<word.size(); ++i) {
            if (node->children[word[i] - 'a'] == nullptr) {
                return -1;
            } else {
                node = node->children[word[i] - 'a'];
            }
        }
        return node->idx;
    }
private:
    TrieNode* root;
    
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */