class Solution {
public:
    void solve(int i,int k,vector<int>&person,int &ans){
        if(person.size() == 1){
            ans = person[0];
            return;
        }
        int index = (i + k - 1) % person.size();
        person.erase(person.begin() + index);
        solve(index,k,person,ans);
    }
    int findTheWinner(int n, int k) {
        int ans = -1;
        vector<int>person;
        for(int i=1;i<=n;i++){
            person.push_back(i);
        }
        solve(0,k,person,ans);
        return ans;
        
    }
};