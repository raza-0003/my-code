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
    TreeNode* builTreedPostIn(vector<int>& inorder,int inS,int inE, vector<int>& postorder,int poS,int poE,map<int,int>&mpp){
        if(inS > inE || poS > poE) return nullptr;
        TreeNode* root = new TreeNode(postorder[poE]);
        int inRoot = mpp[postorder[poE]];   // it store index
        int numLeft = inRoot - inS;    // number left (ending index - starting index)
        root->left = builTreedPostIn(inorder,inS,inRoot-1,postorder,poS,poS+numLeft-1,mpp);
        root->right = builTreedPostIn(inorder,inRoot+1,inE,postorder,poS+numLeft,poE-1,mpp);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[inorder[i]] = i;
        }
        return builTreedPostIn(inorder,0,n-1,postorder,0,n-1,mpp);
    }
};