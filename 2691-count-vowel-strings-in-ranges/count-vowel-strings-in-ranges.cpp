class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char>vowel{'a','e','i','o','u'};
        int n = words.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            bool isVowel = (vowel.count((words[i])[0]) && vowel.count(words[i].back()));
            prefix[i+1] = prefix[i] + isVowel;
        }
        // now we can process the query in O(1) time complexity
        vector<int>result;
        for(auto it:queries){
            int start = it[0];
            int end = it[1];
            result.push_back(prefix[end+1]-prefix[start]);
        }
        return result;
    }
};