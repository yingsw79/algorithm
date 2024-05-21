#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/240/

const int N = 30010;
int p[N], d[N], sz[N];

int find(int x) {
    if (p[x] == x) return x;
    int root = find(p[x]);
    d[x] += d[p[x]];
    return p[x] = root;
}

int main() {
    for (int i = 1; i < N; i++) p[i] = i, sz[i] = 1;
    int T;
    scanf("%d", &T);
    while (T--) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        int fa = find(a), fb = find(b);
        if (*op == 'M') {
            if (fa != fb) {  //有方向的合并
                p[fa] = fb;
                d[fa] = sz[fb];  //注意顺序！！
                sz[fb] += sz[fa];
            }
        } else {
            if (fa != fb)
                puts("-1");
            else
                printf("%d\n", max(abs(d[a] - d[b]) - 1, 0));
        }
    }

    return 0;
}