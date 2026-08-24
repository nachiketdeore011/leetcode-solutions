class Solution {
public:
    int totalTilt = 0;

    int subtreeSum(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftSum = subtreeSum(root->left);
        int rightSum = subtreeSum(root->right);

        // Tilt of current node
        totalTilt += abs(leftSum - rightSum);

        // Return sum of current subtree
        return root->val + leftSum + rightSum;
    }

    int findTilt(TreeNode* root) {
        subtreeSum(root);
        return totalTilt;
    }
};