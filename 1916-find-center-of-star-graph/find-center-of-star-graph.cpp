class Solution {
public:
    int f(int a1, int a2,int b1,int b2){
        if(a1 == b1 || a1 == b2){
            return a1;
        }
        else{
            return a2;
        }
    }
    int findCenter(vector<vector<int>>& edges) {
        // this function is works because it tell star confirm hai!!
       return f(edges[0][0],edges[0][1],edges[1][0],edges[1][1]);
    }
};