/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> arr;
        vector<int> ans;
        inorder(root, arr);
        if (arr.size() == 1) {
            return arr;
        }
        int left = -1;
        int right = -1;
        if (arr.back() < target) {
            left = arr.size() - 1;
            right = arr.size();
        } else if (arr[0] > target) {
            left = -1;
            right = 0;
        } else {
            for (int i=0; i<arr.size() - 1; ++i) {
                if (arr[i] <= target && arr[i + 1] >= target) {
                    left = i;
                    right = i + 1;
                    break;
                }
            }
        }
        
        while (left >= 0 && right < arr.size() && k > 0) {
            if (abs(arr[left] - target) > abs(arr[right] - target)) {
                ans.push_back(arr[right]);
                right ++;
            } else {
                ans.push_back(arr[left]);
                left --;
            }
            k --;
        }
        while (left >= 0 && k > 0) {
            ans.push_back(arr[left]);
            left --;
            k --;
        }
        while (right < arr.size() && k > 0) {
            ans.push_back(arr[right]);
            right ++;
            k --;
        }
        return ans;
        
    }
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
};
// Time : O(n)
// Space : O(n)