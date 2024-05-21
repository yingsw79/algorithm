#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/
/*
从 i 向 favorite[i] 连边，可以得到一张有向图。由于每个大小为 k 的连通块都有 k 个点和 k 条边，
所以每个连通块必定有且仅有一个环，且由于每个点的出度均为 1，这样的有向图又叫做内向基环树 (pseudotree)，
由基环树组成的森林叫基环树森林 (pseudoforest)。
 */
//本题一定有环
class Solution {
public:
    int maximumInvitations(vector<int>& fa) {
        int n = fa.size();
        vector<int> indeg(n), dp(n, 1);
        for (int i = 0; i < n; i++) {
            indeg[fa[i]]++;
        }
        vector<int> q(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            if (!indeg[i]) {
                q[++r] = i;
            }
        }
        while (l <= r) {
            int t = q[l++];
            int j = fa[t];
            dp[j] = max(dp[j], dp[t] + 1);
            if (--indeg[j] == 0) q[++r] = j;
        }

        int res = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if (indeg[i]) {
                indeg[i] = 0;
                int cnt = 1;
                for (int j = fa[i]; j != i; j = fa[j]) {
                    cnt++;
                    indeg[j] = 0;
                }
                if (cnt == 2)
                    sum += dp[i] + dp[fa[i]];
                else
                    res = max(res, cnt);
            }
        }
        return max(res, sum);
    }
};

int main() {
    system("pause");
    return 0;
}