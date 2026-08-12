class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int oldColor){
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() ||
            image[i][j] == newColor || image[i][j] != oldColor){
                return;
            }
        
        image[i][j] = newColor;
        dfs(image, i-1, j, newColor, oldColor); //top
        dfs(image, i, j+1, newColor, oldColor); //right
        dfs(image, i+1, j, newColor, oldColor); //bottom
        dfs(image, i, j-1, newColor, oldColor); //left
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};