class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] == 0 && n > 1) return false;
        if(n == 1) return true;
        int maxInd = 0;
        for(int i=0;i<n;i++){
            if(i > maxInd) return false;
            maxInd = max(maxInd,nums[i] + i);
            if(maxInd >= n-1) return true;
        }
        return true;
        
    }
};