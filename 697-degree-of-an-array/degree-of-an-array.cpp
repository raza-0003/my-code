class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // we have to take care of 3 things: a) freq of number,b)first occurace,c)last occurance
        unordered_map<int,int>mpp1; //freq
        unordered_map<int,int>mpp2; //first occurance
        unordered_map<int,int>mpp3; //last occurance
        // lets find freq,occurances
        for(int i=0;i<nums.size();i++){
            if(mpp1.find(nums[i]) == mpp1.end()){
                //not in the mpp;
                mpp2[nums[i]] = i;;
            }
            mpp1[nums[i]]++;
            mpp3[nums[i]] = i;
        }
        // now finding the maximum frequency
        int maxFreq = INT_MIN;
        for(auto it:mpp1){
            maxFreq = max(maxFreq,it.second);
        }
        // finding shortest subarray length with maxFreq
        int minLen = nums.size();
        for(auto it:mpp1){
            if(it.second == maxFreq){
                minLen = min(minLen,mpp3[it.first]-mpp2[it.first]+1);
            }
        }
        return minLen;
    }
};