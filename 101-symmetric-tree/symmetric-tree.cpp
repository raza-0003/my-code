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
    bool checksym(TreeNode* p ,TreeNode* q){
        if(p==nullptr || q==nullptr){
            return p==q;
        }
        //symmetry only occur when leftsubtrree(node->left) = rightsubtree(node->right) && 
        // leftsubtrree(node->right) = rightsubtree(node->left)
        return (p->val==q->val && checksym(p->left,q->right) && checksym(p->right,q->left));  
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        return checksym(root->left,root->right);
        
    }
};