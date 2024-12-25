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
    bool isUnivalTree(TreeNode* root) {
       // iteraive solution using the stack data structure
       if(root == nullptr) return true;
       int value = root->val;
       stack<TreeNode*>st;
       st.push(root);
       while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        if(node->val != value) return false;
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
       }
       return true;
    }
};