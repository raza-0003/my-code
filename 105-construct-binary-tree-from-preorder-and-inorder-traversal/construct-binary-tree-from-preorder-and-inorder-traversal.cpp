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
    TreeNode* builTreedPreIn(vector<int>& inorder,int inS,int inE, vector<int>& preorder,int prS,int prE,map<int,int>&mpp){
        if(inS > inE || prS > prE) return nullptr;
        TreeNode* root = new TreeNode(preorder[prS]);
        int inRoot = mpp[preorder[prS]];   // it store index
        int numLeft = inRoot - inS;    // number left (ending index - starting index)
        root->left = builTreedPreIn(inorder,inS,inRoot-1,preorder,prS+1,prS+numLeft,mpp);
        root->right = builTreedPreIn(inorder,inRoot+1,inE,preorder,prS+numLeft+1,prE,mpp);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[inorder[i]] = i;
        }
        return builTreedPreIn(inorder,0,n-1,preorder,0,n-1,mpp);
    }
};