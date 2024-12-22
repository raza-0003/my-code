class Solution {
public:
    int minFallingPathSum(vector<vector<int>>&matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        // traversing through the first row to store data inside dp
        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int up = matrix[i][j] + dp[i-1][j];
                int uld = matrix[i][j];
                if(j-1>=0) uld += dp[i-1][j-1]; 
                else uld = 1e9;
                int urd = matrix[i][j];
                if(j+1<n) urd+= dp[i-1][j+1];
                else urd = 1e9;
                dp[i][j] = min(up,min(uld,urd));           }
        }
        int mini = 1e9;
        for(int i=0;i<n;i++){
            mini = min(mini,dp[n-1][i]);
        }
        return mini;
    }
};