class Solution {
public:
    int minimizedStringLength(string s) {
        bitset<26>bitchar;
        for(auto ch:s){
            bitchar.set(ch-'a');
        }
        return bitchar.count();
    }
};