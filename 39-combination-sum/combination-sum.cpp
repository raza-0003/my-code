class Solution {
public:
    void possibleUPair(vector<vector<int>>&ans,vector<int>&arr,vector<int>&ds,int ind,int target){
        // base case 
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind] <= target){
                //pick this element bhaijaan
                ds.push_back(arr[ind]);
                possibleUPair(ans,arr,ds,ind,target - arr[ind]);
                ds.pop_back();  // make sure removal of this element
            }
            // not picking this element
            possibleUPair(ans,arr,ds,ind+1,target);
        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        possibleUPair(ans,candidates,ds,0,target);
        return ans;

    }
};