class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int arrSum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            arrSum += nums[i];
        }
        int k = arrSum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(k+1,0));
        if(arrSum & 1) return false;
        // lets try out the tabulation method
        for(int i=0;i<n;i++) dp[i][0] = true;
        for(int i=1;i<n;i++){
            for(int target =0;target<=k;target++){
                bool notTake = dp[i-1][target];
                bool Take = false;
                if(target >= nums[i]){
                    Take = dp[i-1][target-nums[i]];
                }
                dp[i][target] = Take || notTake;
            }
        } 
        return dp[n-1][k];
    }
};