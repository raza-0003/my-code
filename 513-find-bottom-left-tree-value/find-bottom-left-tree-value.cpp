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
    void dfs(TreeNode* root,int depth,int &maxDepth,int &value){
        if(root == nullptr) return;
        if(depth > maxDepth){
            maxDepth = depth;
            value = root->val;
        }
        dfs(root->left,depth+1,maxDepth,value);
        dfs(root->right,depth+1,maxDepth,value);
    }
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* temp = root;
        int value = 0;
        int maxDep = -1;
        dfs(root,0,maxDep,value);
        return value;     
    }
};