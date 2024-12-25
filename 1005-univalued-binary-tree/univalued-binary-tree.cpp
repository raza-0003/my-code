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
    bool inorder(TreeNode* root,int value){
        if(root == nullptr) return true;    //since empty tree is univalued
        return inorder(root->left, value) &&
               root->val == value &&
               inorder(root->right, value);
    }
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr) return true;
        int value = root->val;
        // we should try preorder traversal why we go to the depth
        return inorder(root,value);
        
    }
};