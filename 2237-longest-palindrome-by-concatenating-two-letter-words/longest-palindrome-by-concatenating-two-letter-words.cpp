class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mpp;
        int count = 0;
        for(auto it:words){
            reverse(it.begin(),it.end());
            if(mpp.find(it) != mpp.end()){
                if(mpp[it] != 0){
                    count += 4;
                    mpp[it]--;
                }
                else{
                    reverse(it.begin(),it.end());
                    mpp[it]++;
                }
            }
            else{
                reverse(it.begin(),it.end());
                mpp[it]++;
            }
        }
        for(auto it:mpp){
            if(it.first[0] == it.first[1] && it.second != 0){
                count += 2;
                break;
            }
        }
        return count;
    }
};