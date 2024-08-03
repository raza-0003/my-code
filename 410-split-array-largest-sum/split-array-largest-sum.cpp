class Solution {
public:
    int findS(vector<int>& nums, int k){
        int stu=1,stu_page=0;
        for(int i=0;i<nums.size();i++){
            if(stu_page+nums[i]<=k){
                stu_page+=nums[i];
            }
            else{
                stu++;
                stu_page=nums[i];
            }
        }
        return stu;
    }
    int splitArray(vector<int>& nums, int k){
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        if(k>n) return -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(findS(nums,mid)<=k){
                high=mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
        
    }

};