class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int elem=0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(cnt == 0){
                cnt=1;
                elem = nums[i];
            }
            else if(nums[i] == elem){
                cnt++;
            }
            else{
                cnt--;
            }

        }
        cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == elem){
                cnt++;
            }
        }
        if(cnt > n / 2) return elem;
        return 0;
        
    }
};