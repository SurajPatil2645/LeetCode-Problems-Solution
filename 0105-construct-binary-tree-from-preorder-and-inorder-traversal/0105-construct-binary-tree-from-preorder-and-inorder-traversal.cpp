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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        
        int preIdx = 0;
        return solve(preorder, mp, preIdx, 0, inorder.size() - 1);
    }

    TreeNode* solve(vector<int>& preorder, unordered_map<int, int>& mp, int& preIdx, int left, int right) {
        if (left > right) return nullptr;

        int curr = preorder[preIdx++];
        TreeNode* root = new TreeNode(curr);
        int mid = mp[curr];

        // Build left first because preorder follows root -> left -> right
        root->left = solve(preorder, mp, preIdx, left, mid - 1);
        root->right = solve(preorder, mp, preIdx, mid + 1, right);

        return root;
    }
};
