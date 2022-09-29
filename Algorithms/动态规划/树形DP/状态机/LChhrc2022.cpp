#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/contest/hhrc2022/problems/wFtovi/

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
    vector<int> dfs(TreeNode* root) {  // 子节点0 自己1 父节点2
        if (!root) return vector<int>(3);
        vector<int> res(3), L, R;
        res[1] = 1;
        if (root->left) {
            L = dfs(root->left);
            res[1] += *min_element(L.begin(), L.end());
            res[2] += min(L[0], L[1]);
        }
        if (root->right) {
            R = dfs(root->right);
            res[1] += *min_element(R.begin(), R.end());
            res[2] += min(R[0], R[1]);
        }
        res[0] = 1e9;
        if (root->left) res[0] = res[2] - min(L[0], L[1]) + L[1];
        if (root->right) res[0] = min(res[0], res[2] - min(R[0], R[1]) + R[1]);
        return res;
    }

    int minSupplyStationNumber(TreeNode* root) {
        auto res = dfs(root);
        return min(res[0], res[1]);
    }
};

int main() {
    return 0;
}