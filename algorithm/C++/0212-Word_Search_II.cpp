class TrieNode {
public:
    TrieNode() {
        word = "";
    }
private:
    unordered_map<char, TrieNode*> children;
    string word;
    friend class Solution;
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        TrieNode* root = new TrieNode();
        TrieNode* node = root;
        vector<string> arr;
        for (int i=0; i<words.size(); ++i) {
            string word = words[i];
            node = root;
            for (int j=0; j<word.size(); ++j) {
                
                if (!node->children.count(word[j])) {
                    node->children[word[j]] = new TrieNode();
                } 
                node = node->children[word[j]];
            }
            node->word = word;
            
        }
        node = root;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (node->children.count(board[i][j])) {
                    backtrack(board, i, j, node, arr);
                }
            }
        }
        return arr;
    }
    void backtrack(vector<vector<char>>& board, int i, int j, TrieNode* parent, vector<string>& arr) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || !parent->children.count(board[i][j])) {
            return;
        }
        
        char ch = board[i][j];
        TrieNode* node = parent->children[ch];
        if (node->word != "") {
            arr.push_back(node->word);
            node->word = "";
        }
        board[i][j] = '&';
        
        backtrack(board, i + 1, j, node, arr);
        backtrack(board, i - 1, j, node, arr);
        backtrack(board, i, j + 1, node, arr);
        backtrack(board, i, j - 1, node, arr);
        board[i][j] = ch;
        if (node->children.empty()) {
            parent->children.erase(ch);
        }
    }
};