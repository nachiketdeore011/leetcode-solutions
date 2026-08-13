class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int leftLen, rightLen, maxLen, len;

        Node() {
            leftChar = rightChar = '#';
            leftLen = rightLen = maxLen = len = 0;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.leftLen = a.leftLen;
        if (a.leftLen == a.len && a.rightChar == b.leftChar)
            res.leftLen = a.len + b.leftLen;

        res.rightLen = b.rightLen;
        if (b.rightLen == b.len && a.rightChar == b.leftChar)
            res.rightLen = b.len + a.rightLen;

        res.maxLen = max(a.maxLen, b.maxLen);

        if (a.rightChar == b.leftChar)
            res.maxLen = max(res.maxLen, a.rightLen + b.leftLen);

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];
            tree[node].leftLen = 1;
            tree[node].rightLen = 1;
            tree[node].maxLen = 1;
            tree[node].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node].leftChar = c;
            tree[node].rightChar = c;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].maxLen);
        }

        return ans;
    }
};