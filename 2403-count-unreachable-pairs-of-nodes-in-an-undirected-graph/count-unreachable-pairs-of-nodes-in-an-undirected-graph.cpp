class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i,vector<int>&parent){
        if(i == parent[i]){
            return i;
        }
        return parent[i] = find(parent[i],parent);
    }
    void Union(int x,int y){
        int x_parent = find(x,parent);
        int y_parent = find(y,parent);
        if(x_parent == y_parent){
            return;
        }
        if(rank[x_parent] > rank[y_parent]){
            // x ko papa bana do
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            // y ko papa bana do
            parent[x_parent] = y_parent;
        }
        else if(rank[x_parent] == rank[y_parent]){
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        rank.resize(n);
        parent.resize(n);
        long long components = n; 
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(auto edge:edges){
            int x = edge[0];
            int y = edge[1];
            if(find(x,parent) != find(y,parent)){
                components--;
                Union(x,y);
            }
        }
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[find(i,parent)]++;
        }
        long long remaining = n;
        long long ans = 0;
        for(auto it:mpp){
            ans += it.second * (remaining - it.second);
            remaining -= it.second;
        }
        return ans;
    }
};