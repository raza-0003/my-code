class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int l1 = nums1.size();
        int l2 = nums2.size();
        for(int i=0;i<l1;i++){
            bool found = false;
            for(int j=0;j<l2;j++){
                if(nums2[j]==nums1[i]){
                    found = true;
                    bool foundgreater =  false;
                    for(int k=j+1;k<l2;k++){
                        if(nums2[k]>nums1[i]){
                            ans.push_back(nums2[k]);
                            foundgreater = true;
                            break;
                        }
                    }
                    if(!foundgreater) ans.push_back(-1);
                    break;
                }
            }
            if(!found) ans.push_back(-1);

        }
        return ans;
        
    }
};