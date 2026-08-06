class Solution {
public:
    int k, ans;

    void dfs(TreeNode* r) {
        if (!r) return;

        dfs(r->left);

        if (--k == 0) {
            ans = r->val;
            return;
        }

        dfs(r->right);
    }

    int kthSmallest(TreeNode* r, int x) {
        k = x;
        dfs(r);
        return ans;
    }
};