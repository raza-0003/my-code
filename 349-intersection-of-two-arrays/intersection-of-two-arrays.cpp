class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st;
        vector<int>ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2){
            for(int i=0;i<n2;i++){
                st.insert(nums2[i]);
            }
            for(int i=0;i<n1;i++){
                if(st.find(nums1[i]) != st.end()){
                    ans.push_back(nums1[i]);
                    st.erase(nums1[i]);
                }
            }
        }
        else {
            for(int i=0;i<n1;i++){
                st.insert(nums1[i]);
            }
            for(int i=0;i<n2;i++){
                if(st.find(nums2[i]) != st.end()){
                    ans.push_back(nums2[i]);
                    st.erase(nums2[i]);

                }
            }
        }
        return ans;

    }
};