class Solution {
public:
    int find(int i,vector<int>&parent){
        if(i == parent[i]){
            return i;
        }
        return parent[i] = find(parent[i],parent);
    }
    void Union(int x,int y,vector<int>&parent,vector<int>&rank){
        int x_parent = find(x,parent);
        int y_parent = find(y,parent);
        if(x_parent == y_parent){
            return;
        }
        if(rank[x_parent] > rank[y_parent]){
            // x papa banega
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            // y papa banega
            parent[x_parent] = y_parent;
        }
        else if(rank[x_parent] == rank[y_parent]){
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        int components = n;
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(auto edge:connections){
            int x = edge[0];
            int y = edge[1];
            if(find(x,parent) != find(y,parent)){
                components--;
                Union(x,y,parent,rank);
            }
        }
        return components - 1;
    }
};