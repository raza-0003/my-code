class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>indeg(n,-0);
        vector<vector<int>> adjRev(n);
        // creating an rev of graph by help of the graph
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                // before i-->it
                //after it-->i
                adjRev[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        //now i get the node which having indegree of 0 that is terminal node;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adjRev[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
       
        
    }
};