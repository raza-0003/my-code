class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int arrSum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            arrSum += nums[i];
        }
        int k = arrSum/2;
        vector<bool>prev(k+1,0),curr(k+1,0);
        if(arrSum & 1) return false;
        // lets try out the tabulation method(also space optimisation use)
        if(nums[0] <= k) prev[nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int target =0;target<=k;target++){
                bool notTake = prev[target];
                bool Take = false;
                if(target >= nums[i]){
                    Take = prev[target-nums[i]];
                }
                curr[target] = Take || notTake;
            }
            prev = curr;
        } 
        return prev[k];
    }
};