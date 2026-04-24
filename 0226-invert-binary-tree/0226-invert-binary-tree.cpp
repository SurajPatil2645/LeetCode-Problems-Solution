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
    TreeNode* invert(TreeNode* root){
        if(root==nullptr) return nullptr;

        TreeNode* left1 = invert(root->right);
        TreeNode* right1 = invert(root->left);
        root->left = left1;
        root->right=right1;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* temp = invert(root);
        return temp;
    }
};