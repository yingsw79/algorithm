#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

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
    int res = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = 0, r = 0;
        if (root->left) {
            l = dfs(root->left);
            l = root->val == root->left->val ? l + 1 : 0;
        }
        if (root->right) {
            r = dfs(root->right);
            r = root->val == root->right->val ? r + 1 : 0;
        }
        res = max(res, l + r);
        return max(l, r);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}