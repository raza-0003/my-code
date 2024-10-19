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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr){
            return ans;
        }
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            //preorder root left right
            ans.push_back(root->val);
            // pahle right isliye stack work on lifo pahle left chahiye toh firstly right put karna padega
            if(root->right!=nullptr){
                st.push(root->right);
            }
            if(root->left!=nullptr){
                st.push(root->left);
            }

        }
        return ans;
        
    }
};