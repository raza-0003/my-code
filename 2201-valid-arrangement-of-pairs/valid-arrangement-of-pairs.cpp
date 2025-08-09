class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // step-1 creating the adj, step-2 finding indeg and outdeg
        unordered_map<int,int>indeg,outdeg;
        unordered_map<int,vector<int>>adj;
        for(auto it:pairs){
            int u = it[0];
            int v = it[1];
            // u-->v
            outdeg[u]++;
            indeg[v]++;
            adj[u].push_back(v);
        }
        int startNode = -1;
         for(auto it:adj){
            int node = it.first;
            if(outdeg[node] - indeg[node] == 1){
                startNode = node;
                break;
            }
        }
        if (startNode == -1) {
            startNode = adj.begin()->first; // Euler circuit case
        }

        // step-3 simply do the khandani dfs here
        vector<int>EulerPath;
        stack<int>st;   // to perform euler path
        st.push(startNode);
        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int nbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(nbr);
            }else{
                // koi neighbour nahi hai path me jaane ko ready hai
                EulerPath.push_back(curr);
                st.pop();
            }
        }
        reverse(EulerPath.begin(),EulerPath.end());
        // step-4 build your ans;
        vector<vector<int>>result;
        for(int i=0;i<EulerPath.size()-1;i++){
            result.push_back({EulerPath[i],EulerPath[i+1]});
        }
        return result;   
    }
};