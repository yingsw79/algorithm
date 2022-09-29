#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/contest/hhrc2022/problems/VAc7h3/

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
    vector<TreeNode*> res;
    unordered_map<string, int> mp;

    string dfs(TreeNode* root) {
        if (!root) return "";
        string s = '(' + dfs(root->left) + ')' + to_string(root->val) + '(' + dfs(root->right) + ')';
        if (++mp[s] == 2) res.push_back(root);
        return s;
    }

    vector<TreeNode*> lightDistribution(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int main() {
    return 0;
}