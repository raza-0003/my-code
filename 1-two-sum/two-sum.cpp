class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum += nums[i] + nums[j];
                if(sum == target) return {i,j};
                else sum = 0;
            }
        }
        return {-1,-1};
    }
};