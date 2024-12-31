class Solution {
public:
    int globalMax;
    int f(int index,vector<int>& nums,vector<int>&dp){
        if(index == 0){
            return nums[0];
        }
        //calculating previous sum;
        if(dp[index]!=-1) return dp[index];
        // we have choices: 1)go with prev subarray 2)getting alone
        int withprev = f(index-1,nums,dp) + nums[index];
        int alone = nums[index];
        int maxEnding = max(withprev,alone);
        globalMax = max(globalMax,maxEnding);
        return dp[index] = maxEnding; // note this line is very important(returning maxEnding not globalMax)
    }
    int maxSubArray(vector<int>& nums) {
        globalMax = nums[0];
        int n = nums.size();
        vector<int>dp(n,-1);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            int withprev = dp[i-1] + nums[i];
            int alone = nums[i];
            dp[i] = max(withprev,alone);
            globalMax = max(globalMax,dp[i]);
        }
        return globalMax;
        
    }
};