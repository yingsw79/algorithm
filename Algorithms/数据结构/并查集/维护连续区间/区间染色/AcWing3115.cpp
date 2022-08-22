#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/3118/

const int N = 1000010;
int fa[N], cl[N];  // fa[i]第 i 个元素右边第一个未被染色的端点
int n, m, p, q;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for (int i = 1; i <= n + 1; i++) fa[i] = i;

    for (int i = m; i; i--) {  // 倒序染色
        int a = (i * p + q) % n + 1, b = (i * q + p) % n + 1;
        int l = min(a, b), r = max(a, b);  // 涂色区间范围[l,r]
        l = find(l);                       // 从右边第一个未被染色的点开始涂色
        while (l <= r) {
            cl[l] = i;            // 染成颜色i
            fa[l] = find(l + 1);  // 标记已染色
            l = find(l);          // 跳到下一个未被染色的点
        }
    }

    for (int i = 1; i <= n; i++) printf("%d\n", cl[i]);

    return 0;
}