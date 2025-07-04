class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxMulp = INT_MIN;
        for(int i=0;i<n;i++){
            int mul = 1;
            for(int j=i;j<n;j++){
                mul *= nums[j];
                maxMulp = max(maxMulp,mul);
            }
        }
        return maxMulp;
    }
};