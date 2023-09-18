#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/description/361/

const int N = 1000010;
int h[N], e[N], ne[N], idx;
int n, fa, son;
int f[N][2];
bool st[N], flag;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void find(int u, int rt) {
    st[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == rt) {
            fa = u, son = j;
            return;
        }
        if (st[j]) continue;
        find(j, rt);
    }
}

void dp(int u, int rt) {
    f[u][0] = 0;
    int tmp = -INF;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == rt) continue;
        dp(j, rt);
        f[u][0] += max(f[j][0], f[j][1]);
        tmp = max(tmp, f[j][0] - max(f[j][0], f[j][1]));
    }
    if (u == fa && flag)
        f[u][1] = 1 + f[u][0];
    else
        f[u][1] = 1 + f[u][0] + tmp;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        add(a, i);  //建有向外向树，方便断环和树形DP
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i]) continue;
        fa = son = 0;
        find(i, i);
        if (fa) {
            flag = false;  //每次都要初始化！！！！！！！！
            dp(son, son);
            int t = max(f[son][0], f[son][1]);
            flag = true;
            dp(son, son);
            t = max(t, f[son][0]);
            res += t;
        }
    }
    printf("%d\n", res);
    return 0;
}