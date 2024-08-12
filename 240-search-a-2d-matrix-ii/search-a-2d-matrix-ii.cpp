class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int rows=0;
        int cols=m-1;
        while(cols>=0 && rows<n){
            if(matrix[rows][cols]==target){
                return true;
            }
            else if(matrix[rows][cols]>target){
                cols--;
            }
            else{
                rows++;
            }
        }
        return false;
        
    }
};