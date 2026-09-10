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
    int count = 0;

    pair<int, int> postOrder(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        pair<int, int> left = postOrder(root->left);
        pair<int, int> right = postOrder(root->right);

        int subtreeSum = left.first + right.first + root->val;
        int numNodes = left.second + right.second + 1;

        if (root->val == (subtreeSum / numNodes)) {
            count++;
        }

        return {subtreeSum, numNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return count;
    }
};