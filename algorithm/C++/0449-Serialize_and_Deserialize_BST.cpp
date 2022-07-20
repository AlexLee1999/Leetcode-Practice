/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        string s = "";
        while (!myQueue.empty()) {
            TreeNode* front = myQueue.front();
            myQueue.pop();
            if (front == nullptr) {
                s += "# ";
                continue;
            }
            s += to_string(front->val);
            s += " ";
            myQueue.push(front->left);
            myQueue.push(front->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec_s;
        stringstream ss(data);
        string val;
        while (ss >> val) {
            vec_s.push_back(val);
        }
        if (vec_s[0] == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(vec_s[0]));
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int i = 1;
        while (i < vec_s.size()) {
            TreeNode* node = myQueue.front();
            myQueue.pop();
            if (vec_s[i] != "#") {
                node->left = new TreeNode(stoi(vec_s[i]));
                myQueue.push(node->left);
            }
            i ++;
            if (vec_s[i] != "#") {
                node->right = new TreeNode(stoi(vec_s[i]));
                myQueue.push(node->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;