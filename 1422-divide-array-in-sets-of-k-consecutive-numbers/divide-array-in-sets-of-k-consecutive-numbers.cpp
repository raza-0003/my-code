class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto [card,freq]:mpp){
            if(freq > 0){
                for(int i=1;i<k;i++){
                    if(mpp[card + i] < freq){
                        // consequitive nhi ho sakta 
                        return false;
                    }
                    mpp[card + i] -= freq;
                }
            }
        }
        return true;
        
    }
};