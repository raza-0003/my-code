class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>prefixCnt;
        int n = nums.size();
        prefixCnt[0] = 1;
        int prefixSum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            prefixSum += nums[i];
            if(prefixCnt.find(prefixSum - goal) != prefixCnt.end()){
                cnt += prefixCnt[prefixSum - goal];
            }
            prefixCnt[prefixSum]++;
        }
        return cnt;
        
    }
};