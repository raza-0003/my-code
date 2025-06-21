class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char,int>mpp;
        int n = word.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            mpp[word[i]]++;
        }
        vector<int>freq;
        for(auto it:mpp){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end());
        int minDeletion = INT_MAX;
        for(int i=0;i<freq.size();i++){
            int del = 0;
            int tar = freq[i];
            for(int j=0;j<freq.size();j++){
                if(freq[j] < tar){
                    del += freq[j];
                }
                else if(freq[j] - tar > k){
                    del += freq[j] - (tar + k);
                }
            }
            minDeletion = min(minDeletion,del);
        }
        return minDeletion;


        
    }
};