class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        vector<int>ans;
        for(auto [num,freq]:mpp){
            if(freq > n /3){
                ans.push_back(num);
            }
        }
        return ans;
        
    }
};