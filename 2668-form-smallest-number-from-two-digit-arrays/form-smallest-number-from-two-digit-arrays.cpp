class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int leftnum = 1e9;
        int rightnum = 1e9;
        unordered_set<int>st(nums1.begin(),nums1.end());
        int mini2 = 1e9;
        for(auto it:nums2){
            if(st.count(it)>0 && it < mini2){
                mini2 = it;
            }
        }
        for(int i=0;i<nums1.size();i++){
            leftnum = min(nums1[i],leftnum);
        }
        for(int i=0;i<nums2.size();i++){
            rightnum = min(nums2[i],rightnum);
        }
        int mini = min(leftnum,rightnum);
        int maxi = max(leftnum,rightnum);
        string result = to_string(mini) + to_string(maxi);
        return min(stoi(result),mini2) ;
    }
};