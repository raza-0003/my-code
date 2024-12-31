class Solution {
public:
    bool f(int index,vector<int>&nums,vector<int>&dp){
        int n = nums.size();
        //covering all the base cases
        if(index == n-1) return true;
        if(index>=n) return false;
        //exploring all the paths 
        if(dp[index]!=-1) return dp[index];
        int maxJumps = nums[index];
        for(int jump =1;jump<=maxJumps;jump++){
            if(f(index + jump,nums,dp) == true){
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1); 
        return f(0,nums,dp);
        //start recursion from back side
        //find(ind,nums) --> signifies that can i reach at (n-1) from index = 0;
    }
};