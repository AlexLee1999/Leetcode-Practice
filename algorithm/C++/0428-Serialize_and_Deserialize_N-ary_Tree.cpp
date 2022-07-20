/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s = "";
        serialize_dfs(root, s);
        return s;
    }
    
    void serialize_dfs(Node* root, string& s) {
        if (root == nullptr) {
            return;
        }
        s += to_string(root->val);
        s += " ";
        s += to_string(root->children.size());
        s += " ";
        for (int i=0; i<root->children.size(); ++i) {
            serialize_dfs(root->children[i], s);
        }
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        stringstream ss(data);
        return deserialize_dfs(ss);
    }
    
    Node* deserialize_dfs(stringstream& ss) {
        string val;
        string size;
        ss >> val;
        ss >> size;
        Node* node = new Node(stoi(val), {});
        for (int i=0; i<stoi(size); ++i) {
            node->children.push_back(deserialize_dfs(ss));
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));