class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1=0,cand2=0;
        int cnt1=0,cnt2=0;
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(cnt1 == 0 && nums[i] != cand2){
                cnt1 = 1;
                cand1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != cand1){
                cnt2 = 1;
                cand2 = nums[i];
            }
            else if(nums[i] == cand1) cnt1++;
            else if(nums[i] == cand2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        // since we are not assurre that ki majority element exist or not
        // upar jo cnt1,cnt2 that does not signify anything brother
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == cand1){
                cnt1++;
            }
            else if(nums[i] == cand2){
                cnt2++;
            }
        }
        if(cnt1 > n/3){
            ans.push_back(cand1);
        }
        if(cnt2 > n/3){
            ans.push_back(cand2);
        }
        return ans;
    }
};