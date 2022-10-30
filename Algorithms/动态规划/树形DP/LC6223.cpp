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
    // unordered_map<int, int> height, res;
    int height[N]{}, res[N]{};

    int dfs(TreeNode* root) {
        if (!root) return 0;
        height[root->val] = max(dfs(root->left), dfs(root->right)) + 1;
        return height[root->val];
    }

    void dfs(TreeNode* root, int depth, int rest_h) {
        if (!root) return;
        depth++;
        res[root->val] = rest_h;
        dfs(root->left, depth, max(rest_h, height[root->right ? root->right->val : 0] + depth));
        dfs(root->right, depth, max(rest_h, height[root->left ? root->left->val : 0] + depth));
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root);
        dfs(root, -1, 0);
        for (int i = 0; i < queries.size(); ++i)
            queries[i] = res[queries[i]];
        return queries;
    }
};

int main() {
    return 0;
}