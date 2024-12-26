class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int>ans;
        map<char,int>mpp;
        mpp['I'] = 0;
        mpp['D'] = n;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                ans.push_back(mpp['I']);
                mpp['I']++;
            }
            else{
                ans.push_back(mpp['D']);
                mpp['D']--;
            }
        }
        ans.push_back(mpp['I']);
        return ans;
    }
};