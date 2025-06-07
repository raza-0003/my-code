class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxSum = 0;
        for(int i=0;i<k;i++){
            maxSum += cardPoints[i];
        }
        // pahle left ke charo le liye
        lsum = maxSum;
        // ab ek ek karke ek right ka uthayenge and ek left ka hata te jayenge
        int rInd = cardPoints.size() - 1;
        for(int i=k-1;i>=0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rInd];
            rInd--;
            maxSum = max(maxSum,lsum + rsum);
        }
        return maxSum;

    }
};