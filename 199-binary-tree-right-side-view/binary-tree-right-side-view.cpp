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
    void recursion_right(TreeNode* root,int level,vector<int>&ans){
        if(root==nullptr){
            return ;
        }
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        recursion_right(root->right,level+1,ans);
        recursion_right(root->left,level+1,ans);


    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recursion_right(root,0,ans);
        return ans;
        
    }
};