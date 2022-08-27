#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// https://www.luogu.com.cn/problem/CF380C
// https://codeforces.com/problemset/problem/380/C

const int N = 1000010;
string s;

struct Node {
    int l, r;
    int lsum, rsum;  // 未匹配的左(右)括号数
} tr[N * 4];

void pushup(Node& u, Node& L, Node& R) {
    u.lsum = L.lsum + R.lsum - min(L.lsum, R.rsum);
    u.rsum = L.rsum + R.rsum - min(L.lsum, R.rsum);
}

void pushup(int p) {
    pushup(tr[p], tr[p << 1], tr[p << 1 | 1]);
}

void build(int p, int l, int r) {
    if (l == r)
        tr[p] = {l, r, s[l - 1] == '(', s[l - 1] == ')'};
    else {
        tr[p] = {l, r};
        int mid = l + r >> 1;
        build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }
}

Node query(int p, int l, int r) {
    if (tr[p].l >= l && tr[p].r <= r) return tr[p];
    int mid = tr[p].l + tr[p].r >> 1;
    if (r <= mid)
        return query(p << 1, l, r);
    else if (l > mid)
        return query(p << 1 | 1, l, r);
    else {
        auto L = query(p << 1, l, r), R = query(p << 1 | 1, l, r);
        Node res;
        pushup(res, L, R);
        return res;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m;
    cin >> s >> m;

    build(1, 1, s.length());

    int l, r;
    while (m--) {
        cin >> l >> r;
        auto t = query(1, l, r);
        int res = r - l + 1 - (t.lsum + t.rsum);
        cout << res << endl;
    }

    return 0;
}