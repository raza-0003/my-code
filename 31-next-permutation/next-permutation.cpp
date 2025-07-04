class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        //finding the pivot element
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }
        // if pivot index does not exist;
        if(pivot == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //finding the element from the right which is greater than pivot
        for(int i=n-1;i>pivot;i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
        reverse(nums.begin() + pivot + 1,nums.end());
    }
};