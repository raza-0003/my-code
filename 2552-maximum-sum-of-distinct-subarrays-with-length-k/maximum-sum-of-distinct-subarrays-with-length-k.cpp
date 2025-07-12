class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        long long maxi = 0;
        long long sum = 0;
        vector<int>visited(1e6,0);
        while(j < n){
            if(!visited[nums[j]]){
                sum += nums[j];
                visited[nums[j]] = 1;
            }
            else{
               // if duplicate found
                while (visited[nums[j]]) {
                    visited[nums[i]] = 0;
                    sum -= nums[i];
                    i++;
                }
                // now safe to include nums[j]
                visited[nums[j]] = 1;
                sum += nums[j];
            }
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k ){
                maxi = max(maxi,sum);
                sum -= nums[i];
                visited[nums[i]] = 0;
                i++;
                j++;
            }
        }
        return maxi;
        
    }
};