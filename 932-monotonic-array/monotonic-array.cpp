class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() < 2) return true;
        int dir = 0;    //0-->unknowm,1-->incresing,-1-->decreasing
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                //increasing
                if(dir == 0) dir=1;
                else if(dir == -1) return false;
            }
            else if(nums[i] < nums[i-1]){
                //decreasing
                if(dir == 0) dir = -1;
                else if(dir == 1) return false;
            }
        }
        return true;
    }
};