class Solution {
public:
    int clockwise(char start,char end){
       return (end-start+26)%26;
    }
    int anticlockwise(char start,char end){
        return (start-end+26)%26;
    }
    int minTimeToType(string word) {
        int n = word.size();
        int minTime = 0;
        char iniptr = 'a';
        for(int i=0;i<n;i++){
            minTime += min(anticlockwise(iniptr,word[i]),clockwise(iniptr,word[i])) + 1;
            iniptr = word[i];
        }
        return minTime;  
    }
};