class Solution {
public:
    int f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int up =f(i-1,j,grid,dp);
        int left =f(i,j-1,grid,dp);
        return dp[i][j] = min(up,left) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        //initialize dp array
        dp[0][0] = grid[0][0];
        // filling first row to calculate 
        for(int i = 1;i<n;i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        //fillig first coloumn
        for(int i=1;i<m;i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                    int up = dp[i-1][j];
                    int left = dp[i][j-1];
                    dp[i][j] = min(up,left) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};