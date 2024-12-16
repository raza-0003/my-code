#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
public:
  vector<int> size,parent,rank;
  DisjointSet(int n){
    rank.resize(n+1,0);
    size.resize(n+1,0); // ensure that no problem for 0 as well as 1 based indexing
    parent.resize(n+1,0);
    for(int i=0;i<=n;i++){
      parent[i] = i;
      size[i] = 1;
    }
  }
  int findUParent(int node){
    if(node == parent[node]){ // base condition for recursion
      return node;
    }
    return parent[node] = findUParent(parent[node]);

  }
  void unionByRank(int u,int v){
    int ulp_u = findUParent(u);
    int ulp_v = findUParent(v);
    if(ulp_u == ulp_v) return ;
    if(rank[ulp_u] < rank[ulp_v]){
      parent[ulp_u] = ulp_v;
      // no change in the rank bcoz smaller is attached to larger
    }
    else if(rank[ulp_v] < rank[ulp_u]){
      parent[ulp_v] = ulp_u;
    }
    else{
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;

    }
  }
  void unionBySize(int u,int v){
    int ulp_u = findUParent(u);
    int ulp_v = findUParent(v);
    if(ulp_u == ulp_v) return;
    if(rank[ulp_u] < rank[ulp_v]){
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else{
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // lets divide this question into three steps
        // steps-01 -->lets create a disjoint set by connectiong node to the mail
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mapMailNode; //{emails,node(name of person)}
        for(int i=0;i<n;i++){ // i--> represent the name of the person
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    //it means mail nhi mila mapMailNode mai
                    mapMailNode[mail] = i;  // i isliye bcoz i rep as the name
                }
                else{
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }
        // step2 --> merging the mails according to their disjoint set
        vector<string> mergeMail[n];
        for(auto it:mapMailNode){
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergeMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        // rearranging and sorting them in order to set merged with the name 
        for(int i=0;i<n;i++){
            if(mergeMail[i].size() == 0) continue;
            // sort the merged mail 
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;   
    }
};