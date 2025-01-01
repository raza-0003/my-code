class Solution {
public:
    void perm(int index,vector<int>&arr,vector<vector<int>>&ans){
        int n = arr.size();
        if(index == n){
            ans.push_back(arr);
            return;
        }
        for(int i=index;i<n;i++){
            swap(arr[index],arr[i]);
            perm(index+1,arr,ans);
            swap(arr[index],arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        perm(0,nums,ans);
        return ans;
    }
};