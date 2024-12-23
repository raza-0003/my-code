class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string conc1 = "";
        string conc2 = "";
        // lets concatinate word1
        for(int i=0;i<word1.size();i++){
            conc1 += word1[i];
        }
        for(int i=0;i<word2.size();i++){
            conc2 += word2[i];
        }
        if(conc1 == conc2) return true;
        return false;
    }
};