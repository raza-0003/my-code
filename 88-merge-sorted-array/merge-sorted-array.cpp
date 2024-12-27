class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = 0;
        int ptr2 = 0;
        int ind = 0;
        vector<int>ans(n+m,0);
        while(ptr1<m && ptr2<n){
            if(nums1[ptr1] < nums2[ptr2]){
                ans[ind]=nums1[ptr1];
                ind++;
                ptr1++;
            }
            else{
                ans[ind] = nums2[ptr2];
                ptr2++;
                ind++;
            }
        }
        while(ptr1<m){
            ans[ind]=nums1[ptr1];
            ptr1++;
            ind++;
        }
        while(ptr2<n){
            ans[ind]=nums2[ptr2];
            ptr2++;
            ind++;
        }
        nums1 = ans;
    }
};