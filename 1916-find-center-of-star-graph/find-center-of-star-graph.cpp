class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        map<int,int>mpp;
        for(auto it:edges){
            mpp[it[0]]++;
            mpp[it[1]]++;
        }
        int ans = 0;
        for(auto it:mpp){
            if(it.second == n){
                ans = it.first;
            }
        }
        return ans;
    }
};