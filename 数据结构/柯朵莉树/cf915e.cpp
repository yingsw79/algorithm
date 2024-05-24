#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/CF915E
// https://codeforces.com/problemset/problem/915/E

struct Node {
    int l, r;
    mutable int v;
    Node(int l, int r, int v) : l(l), r(r), v(v) {}
    bool operator<(const Node& a) const { return l < a.l; };
};
set<Node> tr;
int n, q, sum;

auto split(int p) {
    auto it = tr.lower_bound(Node{p, 0, 0});
    if (it != tr.end() && it->l == p) return it;
    --it;
    int l = it->l, r = it->r, v = it->v;
    tr.erase(it);
    tr.emplace(l, p - 1, v);
    return tr.emplace(p, r, v).first;
}

void assign(int l, int r, int v) {  // 统计1的个数
    auto itr = split(r + 1), itl = split(l);
    for (auto it = itl; it != itr; ++it)
        sum -= it->v * (it->r - it->l + 1);
    tr.erase(itl, itr);
    tr.emplace(l, r, v);
    sum += v * (r - l + 1);
}

int main() {
    scanf("%d%d", &n, &q);

    sum = n;
    tr.emplace(1, 1e9, 1);

    int l, r, k;
    while (q--) {
        scanf("%d%d%d", &l, &r, &k);
        if (k == 1)
            assign(l, r, 0);
        else
            assign(l, r, 1);
        printf("%d\n", sum);
    }

    return 0;
}