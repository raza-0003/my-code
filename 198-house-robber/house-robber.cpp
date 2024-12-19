class Solution {
public:
    int rob(vector<int>& nums) {
        //lets cover edges cases
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int oddsum = 0;
        int evensum = 0;
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                evensum = max(oddsum,evensum+nums[i]);
            }
            else{
                oddsum = max(evensum,nums[i]+oddsum);
            }
        }
        return  max(oddsum,evensum);
    }
};