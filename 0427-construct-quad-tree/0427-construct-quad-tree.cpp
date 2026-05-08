/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size());
    }
    
    Node* helper(vector<vector<int>>& grid, int r, int c, int n) {
        if (isAllSame(grid, r, c, n)) {
            return new Node(grid[r][c], true);
        }
        
        Node* root = new Node(true, false);
        int half = n / 2;
        
        root->topLeft = helper(grid, r, c, half);
        root->topRight = helper(grid, r, c + half, half);
        root->bottomLeft = helper(grid, r + half, c, half);
        root->bottomRight = helper(grid, r + half, c + half, half);
        
        return root;
    }
    
    bool isAllSame(vector<vector<int>>& grid, int r, int c, int n) {
        int val = grid[r][c];
        for (int i = r; i < r + n; i++) {
            for (int j = c; j < c + n; j++) {
                if (grid[i][j] != val) return false;
            }
        }
        return true;
    }
};