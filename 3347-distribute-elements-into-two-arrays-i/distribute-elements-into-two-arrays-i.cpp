class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            int n1 = arr1.size();
            int n2 = arr2.size();
            if(arr1[n1-1] > arr2[n2-1]){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        for(auto it:arr2){
            arr1.push_back(it);
        }
        return arr1;
        
    }
};