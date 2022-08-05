#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/longest-cycle-in-a-graph/

//找基环树最大环(本题不一定有环)
class Solution1 {  //方法1
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indeg(n);
        for (int i = 0; i < n; i++) {
            int j = edges[i];
            if (j != -1) indeg[j]++;
        }
        vector<int> q(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {  //拓扑排序
            if (!indeg[i]) q[++r] = i;
        }
        while (l <= r) {
            int t = q[l++];
            int j = edges[t];
            if (j != -1 && --indeg[j] == 0) q[++r] = j;
        }

        int res = -1;
        for (int i = 0; i < n; i++) {
            if (indeg[i]) {
                indeg[i] = 0;
                int cnt = 1;
                for (int j = edges[i]; j != i; j = edges[j]) {
                    cnt++;
                    indeg[j] = 0;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};

class Solution2 {  //方法2
public:
    vector<int> p;
    vector<bool> st;
    vector<int> in_stk;
    int ans = -1;

    void dfs(int u, int depth) {  //类似有向图Tarjan算法
        st[u] = true;
        in_stk[u] = depth;

        int j = p[u];
        if (j != -1) {
            if (!st[j]) {
                dfs(j, depth + 1);
            } else if (in_stk[j]) {
                ans = max(ans, depth + 1 - in_stk[j]);
            }
        }

        in_stk[u] = 0;
    }

    int longestCycle(vector<int>& p) {
        this->p = p;
        int n = p.size();
        st = vector<bool>(n);
        in_stk = vector<int>(n);

        for (int i = 0; i < n; i++)
            if (!st[i])
                dfs(i, 1);

        return ans;
    }
};

int main() {
    system("pause");
    return 0;
}