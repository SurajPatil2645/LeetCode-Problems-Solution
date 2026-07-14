class Solution {
public: 
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // Horizontal and Vertical check
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == dig) return false;
            if (board[i][col] == dig) return false;
        }
        
        // 3x3 Grid check
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == dig) return false;
            }
        }
        
        return true;
    } 

    bool helper(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true; 
        } 
        
        int nextRow = row;
        int nextCol = col + 1; 
        if (nextCol == 9) {
            nextRow = row + 1; 
            nextCol = 0; 
        } 
        
        // If the current cell is already filled, move to the next cell
        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }
        
        // Try placing digits from '1' to '9'
        for (char dig = '1'; dig <= '9'; dig++) {
            if (isSafe(board, row, col, dig)) {
                board[row][col] = dig; // Place the digit
                
                if (helper(board, nextRow, nextCol)) {
                    return true; // If it leads to a solution, stop and return true
                }
                
                board[row][col] = '.'; // Backtrack if it doesn't work out
            }
        }
        
        return false;
    } 

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0); 
    } 
};