class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>mpp;
        for(auto it:arr){
            mpp[it]++;
        }
        for(auto it:target){
            if(mpp.count(it) == 0 || mpp[it] == 0){
                return false;
            } 
            mpp[it]--;
        }
        return true;
        
    }
};