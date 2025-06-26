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
    TreeNode* constructTree(vector<int>&inorder,vector<int>&postorder,unordered_map<int,int>&inorderIndexMap ,int &postIndex, int inStart,int inEnd){
        if(inStart > inEnd) return nullptr;
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = inorderIndexMap[rootVal];
        root->right = constructTree(inorder,postorder,inorderIndexMap,postIndex,rootIndex+1,inEnd);
        root->left = constructTree(inorder,postorder,inorderIndexMap,postIndex,inStart,rootIndex-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int,int>inorderIndexMap;
        for(int i=0;i<n;i++){
            inorderIndexMap[inorder[i]] = i;
        }
        int postIndex = n-1;
        return constructTree(inorder,postorder,inorderIndexMap,postIndex,0,n-1);
    }
};