class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mpp1,mpp2;
        vector<int>ans(2,0);
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // Count frequencies in nums1
        for(int i=0;i<n1;i++){
            mpp1[nums1[i]]++;
        }
        
        // Count frequencies in nums2
        for(int i=0;i<n2;i++){
            mpp2[nums2[i]]++;
        }
        
        // Calculate answer1 by checking nums1 elements in nums2
        for(int i=0;i<n1;i++){
            if(mpp2.count(nums1[i])){
                ans[0]++;
            }
        }
        
        // Calculate answer2 by checking nums2 elements in nums1
        for(int i=0;i<n2;i++){
            if(mpp1.count(nums2[i])){
                ans[1]++;
            }
        }
        
        return ans;
    }
};