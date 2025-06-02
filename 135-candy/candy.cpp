class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>candy(n+1,1);
        // doing the left travesal
        // [   a  ,  b ,c ,d,e,f,g,h]
        //    i-1    i         
        for(int i=1;i<n;i++){
           if(ratings[i]>ratings[i-1]){
                candy[i] = candy[i-1] + 1;
           }
        }
        // doing traversal from right to left
        // [a,b,c,d,e,f,g, h,k, l]
        //                   i i+1
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                candy[i] = max(candy[i] ,candy[i+1] + 1);
            }
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            sum += candy[i];
        }
        return sum;
    }
};