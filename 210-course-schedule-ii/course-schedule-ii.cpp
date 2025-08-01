class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&inrec,stack<int>&st){
        visited[node] = true;
        inrec[node] = true;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it,adj,visited,inrec,st)){
                    return true;
                }
            }
            else if(inrec[it] == true){
                return true;
            }
        }
        st.push(node);
        inrec[node] = false;
        return false;    
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<bool>inrec(numCourses,0);
        vector<bool>visited(numCourses,0);
        stack<int>st;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,inrec,st)){
                    // it means there is cycle
                    return {};
                }
            }
        }
        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};