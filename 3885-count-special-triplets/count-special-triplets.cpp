class Solution {
public:
  int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int,int>leftFreq;
        unordered_map<int,int>rightFreq;
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            rightFreq[nums[i]]++;
        }
        for(int j=0;j<n;j++){
           rightFreq[nums[j]]--;
           int leftCnt = leftFreq[nums[j] * 2];
           int rightCnt = rightFreq[nums[j] * 2];
           ans = (ans + ( 1LL * leftCnt * rightCnt)% MOD) % MOD;
           leftFreq[nums[j]]++;
        }
        return ans;
    }
};