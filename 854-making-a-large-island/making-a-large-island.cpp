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
bool isValid(int nrow,int ncol,int n){
    return (nrow>=0 && nrow<n && ncol>=0 && ncol<n);
}
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        // step 01 connecting all the components
        for(int row = 0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 0) continue;
                // traversing all its four direction to connect the the cell having 1
                for(int i=0;i<4;i++){
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    if(isValid(nrow,ncol,n) && grid[nrow][ncol] == 1){
                        int nodeNo = row * n + col;
                        int adjNodeNum = nrow * n + ncol;
                        ds.unionBySize(nodeNo,adjNodeNum);

                    } 
                }
            }
        }
        // step 02 --> try to converting 0--> and check its all the adjacent node
        int mx = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 1) continue;
                set<int>components;
                for(int ind=0;ind<4;ind++){
                    int nrow = row + delRow[ind];
                    int ncol = col + delCol[ind];
                    if(isValid(nrow,ncol,n)){
                        if(grid[nrow][ncol] == 1){
                            components.insert(ds.findUParent(nrow * n + ncol));
                        }
                    }
                }
                int sizeTotal = 0;
                for(auto it:components){
                    sizeTotal += ds.size[it];
                }
                mx = max(mx,sizeTotal+1);
            }
        }
        // step 3--> covering the edge cases
        for(int cellNo =0;cellNo<n*n;cellNo++){
            mx = max(mx,ds.size[ds.findUParent(cellNo)]);
        }
        return mx;
        
        
    }
};