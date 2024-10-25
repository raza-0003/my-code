#include <limits.h>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
         TreeNode* prev = nullptr;
        return isValidBSTHelper(root, prev);
    }
    
private:
    bool isValidBSTHelper(TreeNode* node, TreeNode* &prev) {
        if (node == nullptr) {
            return true;
        }

        // Check left subtree
        if (!isValidBSTHelper(node->left, prev)) {
            return false;
        }

        // Check current node
        if (prev != nullptr && node->val <= prev->val) {
            return false;
        }
        prev = node;

        // Check right subtree
        return isValidBSTHelper(node->right, prev);
    }
};
