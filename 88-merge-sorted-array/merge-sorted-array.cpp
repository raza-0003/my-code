class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;
        int p2 = n-1;
        int ind = m+n-1;
        // merging from the back of array
        while(p1>=0 && p2>=0){
            if(nums1[p1]>nums2[p2]){
                nums1[ind] = nums1[p1];
                p1--;
            }
            else{
                nums1[ind] = nums2[p2];
                p2--;
            }
            ind--;
        }
        while(p2>=0){
            nums1[ind] = nums2[p2];
            ind--;
            p2--;
        }
        
    }
};