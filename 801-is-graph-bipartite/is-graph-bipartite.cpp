class Solution {
public:
    bool bfs(int node,int currcolor,vector<vector<int>>&adj,vector<int>&color){
        color[node] = currcolor;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int elem = q.front();
            q.pop();
            for(auto it:adj[elem]){
                if(color[it] == color[elem]){
                    return false;
                }
                else if(color[it] == -1){
                    color[it] = 1 - color[elem];
                    q.push(it);
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
                if(bfs(i,1,graph,color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};