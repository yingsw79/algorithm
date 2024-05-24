#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://codeforces.com/contest/1638/problem/E
// 珂朵莉树 + 树状数组

const int N = 1000010;
int n, q;
LL tr[N], color[N];

struct Node {
    int l, r;
    mutable int v;
    Node(int _l, int _r, int _v) : l(_l), r(_r), v(_v) {}
    bool operator<(const Node& a) const { return l < a.l; };
};

set<Node> odt;

void add(int x, LL v) {  // 会爆int
    for (; x <= n; x += lowbit(x)) tr[x] += v;
}

LL query(int x) {
    LL res = 0;
    for (; x; x -= lowbit(x)) res += tr[x];
    return res;
}

auto split(int p) {
    auto it = odt.lower_bound(Node{p, 0, 0});
    if (it != odt.end() && it->l == p) return it;
    --it;
    int l = it->l, r = it->r, v = it->v;
    odt.erase(it);
    odt.emplace(l, p - 1, v);
    return odt.emplace(p, r, v).first;
}

void assign(int l, int r, int c) {
    auto itr = split(r + 1), itl = split(l);
    for (auto it = itl; it != itr; ++it) {  // 延迟修改
        add(it->l, color[it->v]);
        add(it->r + 1, -color[it->v]);
    }
    odt.erase(itl, itr);
    odt.emplace(l, r, c);
    add(l, -color[c]), add(r + 1, color[c]);  // 改变颜色后,清空该颜色累加值对区间的影响
}

int find(int p) {  // 查找颜色
    auto it = odt.lower_bound(Node{p, 0, 0});
    if (it != odt.end() && it->l == p) return it->v;
    --it;
    return it->v;
}

int main() {
    scanf("%d%d", &n, &q);

    odt.emplace(1, n, 1);

    char op[10];
    int l, r, c, x;
    while (q--) {
        scanf("%s", op);
        if (op[0] == 'C') {
            scanf("%d%d%d", &l, &r, &c);
            assign(l, r, c);
        } else if (op[0] == 'A') {
            scanf("%d%d", &c, &x);
            color[c] += x;
        } else {
            scanf("%d", &x);
            printf("%lld\n", query(x) + color[find(x)]);
        }
    }

    return 0;
}