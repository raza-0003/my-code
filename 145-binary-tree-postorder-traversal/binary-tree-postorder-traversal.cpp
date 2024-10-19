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
        TreeNode* cur = root;
        stack<TreeNode*>st;
        while(cur!=nullptr || !st.empty() ){
            if(cur!=nullptr){
                st.push(cur);
                cur= cur->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                if(temp == nullptr){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    cur = temp; // note yaha pe maine temp = cur kar diya tha then it shows time limit exceed
                }

            }
        }
        return ans;
        
    }
};