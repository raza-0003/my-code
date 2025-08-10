class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;                
        bool w = false;    

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                w = true;
                k &= i;           
                k &= nums[i];      
            }
        }
        return w ? k : 0;
    }
};