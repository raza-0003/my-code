class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        long long mul = 1;
        int cntzero = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                cntzero++;
            }
            else{
                mul *= nums[i];
            }
        }
        // case-1 
        if(cntzero > 1){
            return ans;
        }
        // case-2
        if(cntzero == 1){
            for(int i=0;i<n;i++){
                if(nums[i] == 0){
                    ans[i] = mul;
                    break;
                }
            }
            return ans;
        }
        for(int i=0;i<n;i++){
            ans[i] = (mul / nums[i]);
        }
        return ans;
        
    }
};