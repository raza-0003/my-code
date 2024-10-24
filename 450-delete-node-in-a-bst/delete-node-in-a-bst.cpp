class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {
            return helper(root);  // Return the modified subtree if root needs to be deleted
        }

        TreeNode* dummy = root;
        while (dummy != nullptr) {
            if (dummy->val > key) {
                if (dummy->left != nullptr && dummy->left->val == key) {
                    dummy->left = helper(dummy->left);  // Correct argument here
                    break;
                } else {
                    dummy = dummy->left;
                }
            } else {
                if (dummy->right != nullptr && dummy->right->val == key) {
                    dummy->right = helper(dummy->right);  // Correct argument here
                    break;
                } else {
                    dummy = dummy->right;
                }
            }
        }
        return root;  // Return the root, not dummy
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr) {
            return root->right;
        } else if (root->right == nullptr) {
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;  // Connect right subtree to the last right node
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;  // Return the last right node
    }
};
