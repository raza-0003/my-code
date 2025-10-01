class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;   // initially all bottles i drink
        int emptyBottles = numBottles;  // qki mai sare bottles ko pee gaya that's why
        while(emptyBottles >= numExchange){
            int newFullBottles = (emptyBottles / numExchange);
            ans += newFullBottles;  // addition hamesha full bottle ka hi hoga
            emptyBottles = (emptyBottles % numExchange) + newFullBottles;   //bache hue empty Bottles + naye empty bottles
        }
        return ans;


    }
};