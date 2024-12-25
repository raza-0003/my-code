class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // firstly we have to make adjacency list 
        if(source == destination) return true;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        //using BFS traversal
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