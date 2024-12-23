class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>mpp1,mpp2;
        for(auto it: arr){
            mpp1[it]++;
        }
        for(auto it:target){
            mpp2[it]++;
        }
       return mpp1==mpp2;
        
    }
};