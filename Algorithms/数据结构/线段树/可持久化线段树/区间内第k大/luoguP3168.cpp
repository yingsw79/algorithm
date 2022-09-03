#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P3168
// https://codeforces.com/gym/102770
// http://acm.hdu.edu.cn/showproblem.php?pid=4417

const int N = 100010;
int m, n;
int root[N], nums[N], idx;
vector<int> st[N], ed[N];

struct Node {
    int ls, rs;
    int cnt;
    LL sum;
} tr[N << 6];

int insert(int p, int l, int r, int x, int v) {
    int q = ++idx;
    tr[q] = tr[p];
    if (l == r) {
        tr[q].cnt += v;
        tr[q].sum += nums[x - 1] * v;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        tr[q].ls = insert(tr[p].ls, l, mid, x, v);
    else
        tr[q].rs = insert(tr[p].rs, mid + 1, r, x, v);
    tr[q].cnt = tr[tr[q].ls].cnt + tr[tr[q].rs].cnt;
    tr[q].sum = tr[tr[q].ls].sum + tr[tr[q].rs].sum;
    return q;
}

LL query(int p, int l, int r, int k) {
    if (l == r) return tr[p].sum / tr[p].cnt * k;
    int mid = l + r >> 1;
    int cnt = tr[tr[p].ls].cnt;
    if (k <= cnt)
        return query(tr[p].ls, l, mid, k);
    else
        return tr[tr[p].ls].sum + query(tr[p].rs, mid + 1, r, k - cnt);
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0, x, y; i < m; ++i) {
        scanf("%d%d%d", &x, &y, &nums[i]);
        st[x].emplace_back(nums[i]), ed[y + 1].emplace_back(nums[i]);
    }

    sort(nums, nums + m);
    int tot = unique(nums, nums + m) - nums;

    for (int i = 1, y; i <= n; ++i) {
        int pre = root[i - 1];  // 注意连续插入的处理！！！
        for (int x : st[i]) {
            y = lower_bound(nums, nums + tot, x) - nums + 1;
            root[i] = insert(pre, 1, tot, y, 1);
            pre = root[i];
        }
        for (int x : ed[i]) {
            y = lower_bound(nums, nums + tot, x) - nums + 1;
            root[i] = insert(pre, 1, tot, y, -1);
            pre = root[i];
        }
    }

    LL res = 1;
    for (int i = 0, x, a, b, c, k; i < n; ++i) {
        scanf("%d%d%d%d", &x, &a, &b, &c);
        k = 1 + ((a * res + b) % c);
        res = tr[root[x]].cnt < k ? tr[root[x]].sum : query(root[x], 1, tot, k);
        printf("%lld\n", res);
    }

    return 0;
}