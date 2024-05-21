#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://codeforces.com/problemset/problem/813/E
// 考虑一个区间[l, r]的某个数a[i], 它对答案有贡献当且仅当
// 前面与其权值相同的数中第k个数的位置(记为pos[i]) < l
// 预处理pos[i], 每次询问就转化为区间[l, r]中有多少个pos[i] < l

const int N = 100010;
int pos[N], root[N], idx;
int n, m, k;
queue<int> q[N];

struct Node {
    int ls, rs, sum;
} tr[N << 5];

int insert(int p, int l, int r, int x) {
    int q = ++idx;
    tr[q] = tr[p];
    if (l == r) {
        tr[q].sum++;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        tr[q].ls = insert(tr[p].ls, l, mid, x);
    else
        tr[q].rs = insert(tr[p].rs, mid + 1, r, x);
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
    scanf("%d%d", &n, &k);
    for (int i = 1, x; i <= n; ++i) {  // 预处理
        scanf("%d", &x);
        q[x].push(i);
        if (q[x].size() > k) {
            pos[i] = q[x].front();
            q[x].pop();
        }
    }

    for (int i = 1; i <= n; ++i)
        root[i] = insert(root[i - 1], 0, n, pos[i]);

    scanf("%d", &m);
    for (int i = 0, res = 0, l, r; i < m; ++i) {
        scanf("%d%d", &l, &r);
        l = (l + res) % n + 1;
        r = (r + res) % n + 1;
        if (l > r) swap(l, r);
        res = query(root[r], root[l - 1], 0, n, l - 1);
        printf("%d\n", res);
    }

    return 0;
}