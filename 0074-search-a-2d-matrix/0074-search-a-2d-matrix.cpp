class Solution {
public:
    bool searchInrow(vector<vector<int>>& mat, int target, int row){
        int n = mat[0].size();
        int st = 0, end = n-1;

        while(st<=end){
            int mid = st + (end - st)/2;
            if(target==mat[row][mid]){
                return true;
            } else if(target > mat[row][mid]){
                st = mid + 1;
            } else{
                end = mid -1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n=mat[0].size();

        int sr=0,er=m-1;
        while(sr <= er){
            int mr=sr+(er-sr)/2;
            if(target>=mat[mr][0] && target <= mat[mr][n-1]){
                return searchInrow(mat, target, mr);
            } else if(target >= mat[mr][n-1]){
                sr=mr+1;
            } else{
                er=mr-1;
            }
        }
        return false;
    }
};