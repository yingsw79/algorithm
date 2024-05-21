#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P4113
// 求区间出现次数>=2的数的个数

const int N = 2000010;
int pre[N], cur[N], root[N], idx;
int n, m, c;

struct Node {
    int ls, rs, sum;
} tr[N << 5];

int insert(int p, int l, int r, int x, int v) {
    int q = ++idx;
    tr[q] = tr[p];
    if (l == r) {
        tr[q].sum += v;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        tr[q].ls = insert(tr[p].ls, l, mid, x, v);
    else
        tr[q].rs = insert(tr[p].rs, mid + 1, r, x, v);
    tr[q].sum = tr[tr[q].ls].sum + tr[tr[q].rs].sum;
    return q;
}

int query(int p, int q, int l, int r, int x) {  // 1~x的前缀和
    if (l == r) return tr[p].sum - tr[q].sum;
    int mid = l + r >> 1;
    if (x <= mid)
        return query(tr[p].ls, tr[q].ls, l, mid, x);
    else
        return tr[tr[p].ls].sum - tr[tr[q].ls].sum + query(tr[p].rs, tr[q].rs, mid + 1, r, x);
}

int main() {
    scanf("%d%d%d", &n, &c, &m);
    for (int i = 1, x; i <= n; ++i) {  // 预处理
        scanf("%d", &x);
        pre[i] = cur[x];
        cur[x] = i;
    }

    for (int i = 1; i <= n; ++i) {
        root[i] = insert(root[i - 1], 0, n, pre[i], -1);
        root[i] = insert(root[i], 0, n, pre[pre[i]], 1);
    }

    for (int i = 0, l, r; i < m; ++i) {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(root[r], root[l - 1], 0, n, l - 1));
    }

    return 0;
}