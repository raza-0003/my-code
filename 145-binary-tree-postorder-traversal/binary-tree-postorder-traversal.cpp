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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr){
            return ans;
        }
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty()){
            // this st1 will contian root right left and st2 also
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left!=nullptr){
                st1.push(root->left);
            }
            if(root->right!=nullptr){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            // to revese root right left (to get left right root)(to reverse) have push these into ans list
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;

        
    }
};