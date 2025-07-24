class Solution {
public:
    unordered_map<string,bool>mpp;
    bool solve(string s1, string s2){
        if(s1 == s2){
            return true;
        }
        if(s1.size() != s2.size()){
            return false;
        }
        if(s1.size() <= 1){
            return false;
        }
        string temp = s1 + "$" + s2;
        if(mpp.find(temp) != mpp.end()){
            return mpp[temp];
        }
        int n = s1.size();
        for(int k=1;k<n;k++){
            // is swap is done
            if(solve(s1.substr(0,k), s2.substr(n-k,k)) &&
                solve(s1.substr(k,n-k),s2.substr(0,n-k)))
                return mpp[temp] = true;
            // if swap is not done
            if(solve(s1.substr(0,k), s2.substr(0,k)) &&
                solve(s1.substr(k,n-k),s2.substr(k,n-k)))
                return mpp[temp] = true;
        }
        return mpp[temp] = false;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};