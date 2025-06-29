class Solution {
public:
    vector<int> findPse(vector<int>& nums){
        int n = nums.size();
        vector<int>pse(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    vector<int> findNse(vector<int>& nums){
        int n = nums.size();
        vector<int>nse(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& nums) {
        vector<int> nse = findNse(nums);
        vector<int> pse = findPse(nums);
        int maxi = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;
    }
};
