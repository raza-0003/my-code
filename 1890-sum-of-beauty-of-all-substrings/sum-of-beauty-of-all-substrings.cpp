class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        if(n == 1 ) return 0;
        int ans = 0;
        for(int i=0;i<n-1;i++){
            map<char,int>mpp;
            int maxFreq = 1;   // bcoz 
            mpp[s[i]]++;
            for(int j=i+1;j<n;j++){
               mpp[s[j]]++;
               maxFreq = max(maxFreq,mpp[s[j]]);
               int minFreq = INT_MAX;
               for(auto &it:mpp){
                    minFreq = min(minFreq,it.second);
               }
               ans += (maxFreq - minFreq);
            }
        }
        return ans;
        
    }
};