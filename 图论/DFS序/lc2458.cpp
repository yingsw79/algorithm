#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/height-of-binary-tree-after-subtree-removal-queries/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    static const int N = 100010;
    int in[N], out[N], d[N], tot = 0;

    void dfs(TreeNode* root, int h) {
        if (!root) return;
        in[root->val] = ++tot;
        d[tot] = h;
        dfs(root->left, h + 1);
        dfs(root->right, h + 1);
        out[root->val] = tot;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        vector<int> L(tot + 2), R(tot + 2);
        for (int i = 1; i <= tot; ++i) L[i] = max(L[i - 1], d[i]);
        for (int i = tot; i; --i) R[i] = max(R[i + 1], d[i]);
        for (int i = 0; i < queries.size(); ++i)
            queries[i] = max(L[in[queries[i]] - 1], R[out[queries[i]] + 1]);
        return queries;
    }
};

int main() {
    return 0;
}