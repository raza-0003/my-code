class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>factorList;
        if((n==1 && k==1) || (n==2 && k==2 )) return k; 
        for(int i=1;i<=n;i++){
            if(n%i == 0){
                factorList.push_back(i);
            }
        }
        int kthFsize = factorList.size();
        if(n > kthFsize && k-1 < kthFsize ) return factorList[k-1];
        else return -1;
        
    }
};