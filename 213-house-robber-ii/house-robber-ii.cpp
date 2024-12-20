class Solution {
public:
    int linRob(vector<int>& nums,int start,int end) {
        //lets cover edges cases
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int oddsum = 0;
        int evensum = 0;
        for(int i=start;i<=end;i++){
            if(i%2 == 0){
                evensum = max(oddsum,evensum+nums[i]); // taking even or skip it
            }
            else{
                oddsum = max(evensum,nums[i]+oddsum);  // taking odd or skip it
            }
        }
        return  max(oddsum,evensum);
    }
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n = nums.size();
        if(n==0) return 0;
        if(n == 1) return nums[0];
        // exclude first or exclude last element
        return max(linRob(nums,1,n-1),linRob(nums,0,n-2));
        
    }
};