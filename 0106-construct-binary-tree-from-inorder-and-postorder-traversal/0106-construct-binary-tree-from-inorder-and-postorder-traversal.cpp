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
    int postIdx;
    unordered_map<int, int> inMap;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }
        
        postIdx = postorder.size() - 1;
        
        return helper(postorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(const vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int inIdx = inMap[rootVal];

        root->right = helper(postorder, inIdx + 1, inEnd);
        root->left = helper(postorder, inStart, inIdx - 1);

        return root;
    }
};
