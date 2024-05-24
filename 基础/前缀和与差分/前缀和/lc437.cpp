#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/path-sum-iii/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    typedef long long LL;
    int pathSum(TreeNode *root, int targetSum) {
        unordered_map<LL, int> mp;
        mp[0] = 1;
        int res = 0;
        function<void(TreeNode *, LL)> dfs = [&](TreeNode *root, LL pre) {
            if (!root) return;
            pre += root->val;
            if (mp.count(pre - targetSum))
                res += mp[pre - targetSum];
            mp[pre]++;
            dfs(root->left, pre);
            dfs(root->right, pre);
            mp[pre]--;
        };
        dfs(root, 0);
        return res;
    }
};

int main() {
    return 0;
}