class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string conc1 = "";
        string conc2 = "";
        int n1 = word1.size();
        int n2 = word2.size();
        // lets concatinate word1
        for(int i=0;i<n1;i++){
            conc1 += word1[i];
        }
        for(int i=0;i<n2;i++){
            conc2 += word2[i];
        }
        if(conc1 == conc2) return true;
        return false;
    }
};