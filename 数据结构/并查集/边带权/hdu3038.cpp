#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// http://acm.hdu.edu.cn/showproblem.php?pid=3038

const int N = 200010;
int p[N], d[N];  //注意方向！！！此处d是相对右侧的距离!!!!!

int find(int x) {
    if (p[x] == x) return x;
    int root = find(p[x]);
    d[x] += d[p[x]];  //路径压缩的同时维护d数组！！！
    return p[x] = root;
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i <= n; i++) p[i] = i, d[i] = 0;  //前缀和需要考虑0！！
        int res = 0;
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--;  //前缀和下标减1！！
            int fa = find(a), fb = find(b);
            if (fa == fb) {
                if (d[a] - d[b] != c) res++;  //d[a] - d[b]是a相对右侧b的距离!!!!!
            } else {
                p[fa] = fb;
                d[fa] = d[b] - d[a] + c;  //注意方向！！此处是向右合并！！
            }
        }
        printf("%d\n", res);
    }

    return 0;
}