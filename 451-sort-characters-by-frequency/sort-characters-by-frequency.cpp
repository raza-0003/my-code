class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int> mpp;
        for(auto ch:s){
            mpp[ch]++;
        }
        vector<pair<char, int>>vec;
        for (auto& p : mpp) {
            vec.push_back(p);
        }
        // Sort by value in decreasing order
        sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        for(auto it:vec){
            //string(count, char)
            ans += string(it.second , it.first);
        }
        return ans;       
    }
};