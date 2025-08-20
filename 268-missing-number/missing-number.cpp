class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xr1 = 1;
        int xr2 = 1;
        for(int i=0;i<n;i++){
            xr1 = xr1 ^ nums[i];
        }
        for(int i=1;i<n+1;i++){
            xr2 = xr2 ^ i;
        }
        return xr1 ^ xr2;
        
    }
};