class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<stack<int>>cnt(26);
        for(int i=0;i<n;i++){
            if(s[i] != '*'){
                cnt[s[i]-'a'].push(i);
            }
            else{
                //  it means it is a star
                for(int j=0;j<26;j++){
                    if(!cnt[j].empty()){
                        s[cnt[j].top()] = '*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(s[i] != '*'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};