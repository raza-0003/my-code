class Solution {
public:
    bool dfs(int node,int currcolor,vector<vector<int>>&adj,vector<int>&color){
        color[node] = currcolor;
        for(auto it:adj[node]){
            if(color[it] == currcolor){
                return false;
            }
            else if(color[it] == -1){
                if(dfs(it,1-currcolor,adj,color) == false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(dfs(i,1,graph,color) == false){
                    return false;
                }
            }
        }
        
        return true;
    }
};