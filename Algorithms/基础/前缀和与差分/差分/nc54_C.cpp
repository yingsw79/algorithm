#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://ac.nowcoder.com/acm/contest/38457/C

const int N = 1010;
LL st[N], ed[N];
int n, h, m, q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> h >> m >> q;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        LL x = (LL)a * m + b, y = (LL)c * m + d;
        st[k] = x, ed[k] = y;
        k++;
    }

    sort(st, st + n);
    sort(ed, ed + n);

    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        LL x = (LL)a * m + b;
        int c = upper_bound(st, st + n, x) - st;
        int d = lower_bound(ed, ed + n, x) - ed;
        if (c - d > 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

    return 0;
}