class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);

        vector<long long> sums;

        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;

            // Process one level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            sums.push_back(sum);
        }

        // Fewer than k levels
        if (sums.size() < k)
            return -1;

        sort(sums.begin(), sums.end(), greater<long long>());

        return sums[k - 1];
    }
};