#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P3567

const int N = 500010;
int a[N], root[N], idx;
int n, m;

struct Node {
    int ls, rs, cnt;
} tr[N << 5];

int insert(int p, int l, int r, int x) {
    int q = ++idx;
    tr[q] = tr[p];
    if (l == r) {
        tr[q].cnt++;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        tr[q].ls = insert(tr[p].ls, l, mid, x);
    else
        tr[q].rs = insert(tr[p].rs, mid + 1, r, x);
    tr[q].cnt = tr[tr[q].ls].cnt + tr[tr[q].rs].cnt;
    return q;
}

int query(int p, int q, int l, int r, int x) {
    if (l == r) return l;
    int mid = l + r >> 1;
    if (tr[tr[p].ls].cnt - tr[tr[q].ls].cnt > x) return query(tr[p].ls, tr[q].ls, l, mid, x);
    if (tr[tr[p].rs].cnt - tr[tr[q].rs].cnt > x) return query(tr[p].rs, tr[q].rs, mid + 1, r, x);
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
        root[i] = insert(root[i - 1], 1, n, a[i]);

    for (int i = 0, l, r; i < m; ++i) {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(root[r], root[l - 1], 1, n, (r - l + 1) / 2));
    }

    return 0;
}