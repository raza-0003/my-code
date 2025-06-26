class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<pair<int,int>>vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),[](auto &a,auto &b){
            return a.second > b.second;
        });
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
        }
        return ans;
        
    }
};