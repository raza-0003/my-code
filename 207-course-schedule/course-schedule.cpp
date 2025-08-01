class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&inrec){
        visited[node] = true;
        inrec[node] = true;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it,adj,visited,inrec)){
                    return true;
                }
            }
            else if(inrec[it] == true){
                return true;
            }
        }
        inrec[node] = false;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<bool>inrec(numCourses,0);
        vector<bool>visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,inrec)){
                    // it means there is cycle
                    return false;
                }
            }
        }
        return true;
    }
};