#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/symmetric-tree/

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
    bool dfs(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;
        else if (!l || !r)
            return false;
        else
            return l->val == r->val && dfs(l->left, r->right) && dfs(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};

int main() {
    return 0;
}