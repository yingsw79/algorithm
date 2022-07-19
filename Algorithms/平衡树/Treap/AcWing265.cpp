#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 33010, INF = 1e7;

int n;
struct Node {
    int l, r;
    int key, val;
} tr[N];

int root, idx;

int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    return idx;
}

void build() {
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
}

void zig(int &p) {
    int q = tr[p].l;
    tr[p].l = tr[q].r, tr[q].r = p, p = q;
}

void zag(int &p) {
    int q = tr[p].r;
    tr[p].r = tr[q].l, tr[q].l = p, p = q;
}

void insert(int &p, int key) {
    if (!p)
        p = get_node(key);
    else if (tr[p].key == key)
        return;
    else if (tr[p].key > key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val) zig(p);
    } else {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val) zag(p);
    }
}

int get_prev(int p, int key) {  // 找到小于等于key的最大数
    if (!p) return -INF;
    if (tr[p].key > key) return get_prev(tr[p].l, key);
    return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int p, int key) {  // 找到大于等于key的最小数
    if (!p) return INF;
    if (tr[p].key < key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main() {
    build();
    scanf("%d", &n);

    LL res = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (i == 1)
            res += x;
        else
            res += min(x - get_prev(root, x), get_next(root, x) - x);

        insert(root, x);
    }

    printf("%lld\n", res);

    return 0;
}
