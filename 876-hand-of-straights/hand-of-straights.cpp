class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        map<int,int>mpp;
        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }
        for(auto [card,freq]:mpp){
            if(freq > 0){
                for(int i=1;i<groupSize;i++){
                    if(mpp[card + i] < freq){
                        return false;
                    }
                    mpp[card + i] -= freq;
                }
            }
        }
        return true;
    }
};