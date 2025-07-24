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
        string temp;
        temp.append(s1);
        temp.push_back(' ');
        temp.append(s2);
        if(mpp.find(temp) != mpp.end()){
            return mpp[temp];
        }
        bool flag = false;
        for(int k=1;k<s1.size();k++){
            if((solve(s1.substr(0,k), s2.substr(s2.size()-k,k)) && solve(s1.substr(k,s1.size()-k),s2.substr(0,s2.size()-k))) ||
                (solve(s1.substr(0,k), s2.substr(0,k)) && solve(s1.substr(k,s1.size()-k),s2.substr(k,s2.size()-k)))
            ){
                flag = true;
                break;
            }
        }
        return mpp[temp] = flag;
        
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);

        
    }
};