class Solution {
public:
    int find(int i,vector<int>&parent){
        if(i == parent[i]){
            return i;
        }
        return parent[i] = find(parent[i],parent);
    }
    void Union(int x,int y,vector<int>&parent){
        int x_parent = find(x,parent);
        int y_parent = find(y,parent);
        if(x_parent == y_parent){
            return;
        }
        else{
            parent[x_parent] = y_parent; 
        }

    }
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26);
        int i = 0;
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
        // firstly evalute all the equality first
        for(auto word:equations){
            if(word[1] == '='){
                int x = word[0]-'a';
                int y = word[3]-'a';
                Union(word[0]-'a',word[3]-'a',parent);
            }
        }
        // now evalute the all enequlity sign
        for(auto word:equations){
            if(word[1] == '!'){
                int x = word[0]-'a';
                int y = word[3]-'a';
                if(find(x,parent) == find(y,parent)){
                    return false;
                }
            }
        }
        return true;
    }
};