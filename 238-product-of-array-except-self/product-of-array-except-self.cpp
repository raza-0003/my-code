class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>premul(n);
        vector<int>sufmul(n);
        premul[0] = 1;
        sufmul[n-1] = 1;
        for(int i=1;i<n;i++){
            premul[i] = nums[i-1] * premul[i-1];
        }
        for(int i=n-2;i>=0;i--){
            sufmul[i] = nums[i+1] * sufmul[i+1];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = premul[i] * sufmul[i];
        }
        return ans;
        
    }
};