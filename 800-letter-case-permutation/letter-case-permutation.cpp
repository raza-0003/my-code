class Solution {
public:
    void solve(int ind,string s,string otp,vector<string>&ans){
        if(ind == s.size()){
            ans.push_back(otp);
            return;
        }
        if(s[ind]>= 97 && s[ind]<= 122){
            string otp1 = otp + s[ind];
            string otp2 = otp;
            otp2 += (s[ind] - 32);
            solve(ind+1,s,otp1,ans);
            solve(ind+1,s,otp2,ans);
        }
        else if(s[ind] >= 65 && s[ind] <= 90){
            string otp1 = otp + s[ind];
            string otp2 = otp;
            otp2 += (s[ind] + 32);
            solve(ind+1,s,otp1,ans);
            solve(ind+1,s,otp2,ans);
        }
        else{
            string otp1 = otp + s[ind];
            solve(ind+1,s,otp1,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string otp = "";
        vector<string>ans;
        solve(0,s,otp,ans);
        return ans;
        
    }
};