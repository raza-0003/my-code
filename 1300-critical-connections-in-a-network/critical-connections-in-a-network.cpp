class Solution {
private:
    int timer = 1;
    void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it:adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
               dfs(it,node,vis,adj,tin,low,bridges); 
               low[node] = min(low[node],low[it]);
               //it-->node
               if(low[it]> tin[node]){
                    // it means it can node be reached to the node if breaken (tod do yeah bandhan)
                    bridges.push_back({it,node});

               } 
            }
            else{
                // means it already visited meaan it can reach to the node if this bandhan is breaken
                low[node] = min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //firstly convert it into the adj list;
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0),tin(n,0),low(n,0);
        vector<vector<int>>bridges; // to storing the bridges
        dfs(0,-1,vis,adj,tin,low,bridges);  //did dfs traversal starting with src 0 and and parent =-1
        return bridges;

        
    }
};