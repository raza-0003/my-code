class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        unordered_set<double>st;
        for(int i=0;i<n/2;i++){
            st.insert((nums[i] + nums[n-i-1])/2.0);
        }
        return st.size(); 
    }
};