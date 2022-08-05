#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/

class TreeAncestor {
    vector<vector<int>> g, fa;
    queue<int> q;
    int t;

public:
    TreeAncestor(int n, vector<int>& parent) {
        t = log(n) / log(2) + 1;
        g.resize(n + 1);
        fa.resize(n + 1, vector<int>(t + 1));
        for (int i = 1; i < n; i++) {
            g[parent[i] + 1].push_back(i + 1);
        }
        q.push(1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& v : g[u]) {
                fa[v][0] = u;
                q.push(v);
                for (int i = 1; i <= t; i++)
                    fa[v][i] = fa[fa[v][i - 1]][i - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        node = node + 1;
        for (int i = 0; i <= t; i++) {
            if (k >> i & 1) node = fa[node][i];
        }
        return node ? node - 1 : -1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main() {
    system("pause");
    return 0;
}