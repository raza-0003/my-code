/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findMaxDistance(map<TreeNode*,TreeNode*>&mpp,TreeNode* target){
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*,int>visited;
        visited[target] = 1;
        int maxi = 0;
        while(!q.empty()){
            int sizee = q.size();
            int flag = 0;
            for(int i=0;i<sizee;i++){
                auto node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    flag = 1;
                    visited[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    flag = 1;
                    visited[node->right] = 1;
                    q.push(node->right);
                }
                if(mpp[node] && !visited[mpp[node]]){
                    flag = 1;
                    visited[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
            }
            if(flag == 1){
                maxi++;
            }
        }
        return maxi;
    } 
    TreeNode* bfsToMapParent(TreeNode* root,map<TreeNode*,TreeNode*>&mpp,int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) res = node;
            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right] = node;
                q.push(node->right);
            }

        }
        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mpp;
        TreeNode* target = bfsToMapParent(root,mpp,start);
        int maxi = findMaxDistance(mpp,target);
        return maxi;
    }
};