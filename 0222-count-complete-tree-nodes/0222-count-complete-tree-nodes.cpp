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
    int countNode(TreeNode* root){
        if(root == nullptr) return 0;
        int leftcount = countNodes(root->left);
        int rightcount = countNodes(root->right);
        return leftcount+rightcount+1;
    }
    int countNodes(TreeNode* root) {
        int count = countNode(root);
        return count;
    }
};