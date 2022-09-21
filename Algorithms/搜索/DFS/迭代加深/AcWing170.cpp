#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/172/

const int N = 110;
int path[N], n;

bool dfs(int u, int depth) {
    if (u == depth) return path[u - 1] == n;
    bool st[N] = {0};
    for (int i = u - 1; i >= 0; --i) {
        for (int j = i; j >= 0; --j) {
            int sum = path[i] + path[j];
            if (sum > n || sum <= path[u - 1] || st[sum]) continue;
            st[sum] = true;
            path[u] = sum;
            if (dfs(u + 1, depth)) return true;
        }
    }
    return false;
}

int main() {
    path[0] = 1;
    while (cin >> n, n) {
        int depth = 1;
        while (!dfs(1, depth)) depth++;
        for (int i = 0; i < depth; i++) cout << path[i] << ' ';
        cout << endl;
    }

    return 0;
}