class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int right = n-1;
        unordered_set<float>st;
        while(left<=right){
            float average = (nums[left] + nums[right])/2.0;
            st.insert(average); 
            left++;
            right--;
        }
        return st.size(); 
    }
};