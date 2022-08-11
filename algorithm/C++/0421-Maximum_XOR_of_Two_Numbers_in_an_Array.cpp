class TrieNode {
public:
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
private:
    TrieNode* children[2];
    int num;
    friend class Solution;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (int i=0; i<nums.size(); ++i) {
            TrieNode* node = root;
            for (int j=31; j>=0; --j) {
                int bit = (nums[i] >> j) & 1;
                if (node->children[bit] == nullptr) {
                    node->children[bit] = new TrieNode();
                }
                node = node->children[bit];
            }
            node->num = nums[i];
        }
        int max_num = 0;
        for (int i=0; i<nums.size(); ++i) {
            max_num = max(max_num, maxXOR(nums[i], root));
        }
        return max_num;
    }
    int maxXOR(int n, TrieNode* node) {
        for (int i=31; i>=0; --i) {
            int bit = (n >> i) & 1;
            if (node->children[1 - bit] == nullptr) {
                node = node->children[bit];
            } else {
                node = node->children[1 - bit];
            }
        }
        return n ^ node->num;
    }
};
// Time : O(n)
// Space : O(n)