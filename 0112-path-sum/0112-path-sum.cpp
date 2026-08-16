class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;

        // If leaf node
        if (root->left == NULL && root->right == NULL)
            return targetSum == root->val;

        // Check left or right subtree
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};