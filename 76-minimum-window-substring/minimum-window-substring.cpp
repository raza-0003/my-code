class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int i=0,j=0;
        int start = 0;
        unordered_map<char,int>mpp;
        for(auto ch:t){
            mpp[ch]++;
        }
        int mini = INT_MAX;
        int count = mpp.size();
        while(j<n){
            char ch = s[j];
            if(mpp.find(ch) != mpp.end()){
                //this char is req
                mpp[ch]--;
                if(mpp[ch] == 0) count--;
            }
            if(count == 0){
                while(count == 0){
                    if(mpp.find(s[i]) != mpp.end()){
                        mpp[s[i]]++;
                        if(mpp[s[i]] == 1){
                            count++;
                            if(j-i+1 < mini){
                                mini = j-i+1;
                                start = i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(mini == INT_MAX) return "";
        return s.substr(start,mini);


    }
};