class Solution {
public:
    int f(int index,vector<int>&dp){
        if(index ==1 || index == 0) return index;
        if(dp[index]!=-1) return dp[index];
        return dp[index] = f(index-1,dp) + f(index-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};