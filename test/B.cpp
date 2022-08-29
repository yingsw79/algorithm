#include <cstdio>
#include <iostream>
#include <set>
#define IN inline
#define RE register
using namespace std;
typedef long long LL;

const int N = 1e6 + 5;
int n, q;
LL tag[N];

struct BIT {
    LL c[N];
    IN int lowbit(int x) { return x & (-x); }
    IN void add(int x, LL v) {
        for (; x <= n; x += lowbit(x)) c[x] += v;
    }
    IN LL Query(int x) {
        LL s = 0;
        for (; x; x -= lowbit(x)) s += c[x];
        return s;
    }
} T;

struct node {
    int l, r;
    mutable int v;
    IN node(int l, int r, int v) : l(l), r(r), v(v){};
    IN bool operator<(const node &a) const { return l < a.l; }
};
set<node> odt;
typedef set<node>::iterator IT;

IN IT split(int x) {
    if (x > n) return odt.end();
    IT it = --odt.upper_bound(node{x, 0, 0});
    if (it->l == x) return it;
    int l = it->l, r = it->r, v = it->v;
    odt.erase(it), odt.insert(node{l, x - 1, v});
    return odt.insert(node{x, r, v}).first;
}
IN void assign(int l, int r, int c) {
    IT itr = split(r + 1), itl = split(l);
    for (RE IT it = itl; it != itr; it++)
        T.add(it->l, tag[it->v]), T.add(it->r + 1, -tag[it->v]);
    odt.erase(itl, itr), odt.insert(node{l, r, c});
    T.add(l, -tag[c]), T.add(r + 1, tag[c]);
}
IN int find(int x) {
    IT it = odt.lower_bound(node{x, 0, 0});
    if (it->l == x) return it->v;
    return (--it)->v;
}

IN void read(int &x) {
    x = 0;
    int f = 1;
    char ch = getchar();
    for (; !isdigit(ch); f = (ch == '-' ? -1 : 1), ch = getchar())
        ;
    for (; isdigit(ch); x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar())
        ;
    x *= f;
}

int main() {
    read(n), read(q), odt.insert(node{1, n, 1});
    char op[10];
    for (RE int l, r, c, x; q; --q) {
        scanf("%s", op);
        if (op[0] == 'C')
            read(l), read(r), read(c), assign(l, r, c);
        else if (op[0] == 'A')
            read(c), read(x), tag[c] += x;
        else
            read(x), printf("%lld\n", T.Query(x) + tag[find(x)]);
    }
}
