class Solution {
public:
    int f(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp,int n){
        if(i == n-1) return triangle[n-1][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + f(i+1,j,triangle,dp,n);
        int diagnal = triangle[i][j] + f(i+1,j+1,triangle,dp,n);
        return dp[i][j] = min(down,diagnal);
    }
    int minimumTotal(vector<vector<int>>&triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagnal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagnal);
            }
        }
        return dp[0][0];
        
    }
};