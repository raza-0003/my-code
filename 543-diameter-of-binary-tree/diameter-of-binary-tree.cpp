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
    int solve(TreeNode* root,int &res){
        // base condition
        if(root == nullptr) return 0;
        // hypothesis
        int left = solve(root->left,res);
        int right = solve(root->right,res);
        // induction
        int temp = 1 + max(left,right);
        int ans = max(temp,1+left+right);
        res = max(ans,res);
        return temp;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        solve(root,res);
        return res-1;
        
    }
};