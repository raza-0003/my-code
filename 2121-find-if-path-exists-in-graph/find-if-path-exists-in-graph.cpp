class Solution {
public:
    void dfs(int node,vector<vector<int>>adj,vector<bool>&visited){
        visited[node] = true;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // firstly we have to make adjacency list 
        if(source == destination) return true;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        q.push(source);
        vector<bool>visited(n,false);
        visited[source] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it:adj[curr]){
                if(it == destination) return true;
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};