class Solution {
public:
    int maxDepth(string s) {
        int maxNestDepth = 0;
        int temp = 0;
        for(auto ch:s){
            if(ch == '('){
                temp++;
                maxNestDepth=max(maxNestDepth,temp);
            }
            else if(ch == ')'){
                temp--;
            }
        }
        return maxNestDepth;
        
        
    }
};