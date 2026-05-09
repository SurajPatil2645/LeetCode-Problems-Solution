class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int i = 0; i < layers; i++) {
            vector<int> elements;
            int r1 = i, c1 = i;
            int r2 = m - 1 - i, c2 = n - 1 - i;
            for (int j = c1; j < c2; j++) elements.push_back(grid[r1][j]);
            for (int j = r1; j < r2; j++) elements.push_back(grid[j][c2]);
            for (int j = c2; j > c1; j--) elements.push_back(grid[r2][j]);
            for (int j = r2; j > r1; j--) elements.push_back(grid[j][c1]);

            int total = elements.size();
            int shift = k % total;
            
            int idx = shift;
            for (int j = c1; j < c2; j++) grid[r1][j] = elements[idx++ % total];
            for (int j = r1; j < r2; j++) grid[j][c2] = elements[idx++ % total];
            for (int j = c2; j > c1; j--) grid[r2][j] = elements[idx++ % total];
            for (int j = r2; j > r1; j--) grid[j][c1] = elements[idx++ % total];
        }

        return grid;
    }
};