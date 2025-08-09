class Solution {
public:
    unordered_map<int,vector<int>> madeAdj(vector<vector<int>>& edges){
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    int findDia(unordered_map<int,vector<int>>&adj,int n){
        // first BFS to find the farthest node from any Node say eg:0
        auto [farthestNode,_] = findFarthestNode(adj,n,0);
        // second BFS from farthest node to find diameter
        auto [_,diameter] = findFarthestNode(adj,n,farthestNode);
        return diameter;
    }
    pair<int,int> findFarthestNode(unordered_map<int,vector<int>>&adj,int n,int srcNode){
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(srcNode);
        visited[srcNode] = true;
        int maxDist = 0;
        int farthestNode = srcNode;
        while(!q.empty()){
            // curr level me itne nodes hai
            int n = q.size();
            // explore its neighbour
            for(int i=0;i<n;i++){
                int currNode = q.front();
                q.pop();
                // update the farthest node
                farthestNode = currNode;
                for(int nbr:adj[currNode]){
                    if(!visited[nbr]){
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            if(!q.empty()){
                maxDist++;
            }
        }
        return {farthestNode,maxDist};
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        unordered_map<int,vector<int>>adj1 = madeAdj(edges1);
        unordered_map<int,vector<int>>adj2 = madeAdj(edges2);
        int dia1 = findDia(adj1,n);
        int dia2 = findDia(adj2,m);
        int combinedDia = (dia1+1)/2 + (dia2+1)/2 + 1;
        return max(max(dia1,dia2),combinedDia);
    }
};