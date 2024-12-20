class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_set<int>st(nums[0].begin(),nums[0].end());
        // traversing in each subsequent array
        for(int i=1;i<nums.size();i++){
            // keep only that element whihch exist in current array baaki ko nikal do
            unordered_set<int>temp;
            for(auto it:nums[i]){
                if(st.count(it)){
                    temp.insert(it);
                }
            }
            st = temp;
        }
        vector<int>ans(st.begin(),st.end());
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};