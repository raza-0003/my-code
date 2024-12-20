class Solution {
public:
    int maxNonAdjSum(vector<int>&nums){
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int Take = nums[i];
            if(i>1) Take += prev2;
            int notTake = 0 + prev1;
            int curi = max(Take,notTake);
            prev2 = prev1;
            prev1 = curi;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);

            }
        }
        return max(maxNonAdjSum(temp1),maxNonAdjSum(temp2));
        
    }
};