#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

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
    int f(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        bool st[n];
        memset(st, 0, sizeof st);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (st[i]) continue;
            for (int j = i; !st[j]; j = idx[j]) st[j] = true;
            cnt++;
        }
        return n - cnt;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (q.size()) {
            vector<int> tmp;
            for (int sz = q.size(); sz--;) {
                auto t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res += f(tmp);
        }
        return res;
    }
};

int main() {
    return 0;
}