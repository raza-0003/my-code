class Solution {
public:
    string f(int start,int end,string &str){
        while(start<end){
            swap(str[start],str[end]);
            start++;
            end--;
        }
        return str;
    }
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i=0;i<n;i+=2*k){
            int start = i;
            int end = min(i+k-1,n-1);
            f(start,end,s);
        }
        return s;
    }
};