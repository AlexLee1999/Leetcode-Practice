class TrieNode{
public:
    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
        isEnd = false;
    }
private:
    vector<TrieNode*> children;
    bool isEnd;
    friend class Trie;
};


class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); ++i) {
        
            
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); ++i) {
            if (node->children[word[i] - 'a'] == nullptr) {
                return false;
            } else{
                node = node->children[word[i] - 'a'];
            }
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0; i<prefix.size(); ++i) {
            if (node->children[prefix[i] - 'a'] == nullptr) {
                return false;
            } else{
                node = node->children[prefix[i] - 'a'];
            }
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */