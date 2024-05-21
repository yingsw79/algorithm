#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 110, M = 1e5 + 10;

int n, m;
struct Node {
    int s, e, l;
    bool operator<(const Node& t) const { return s * t.l < t.s * l; }
} a[N];
int f[M];

void solve() {
    //求恰好的背包DP,为了保证状态都是从起点转移的,要把非起点初始化为无穷大以避免转移
    memset(f, -0x3f, sizeof f);
    f[0] = m = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].s >> a[i].e >> a[i].l, m += a[i].s;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= a[i].s; --j) {
            int pre = j - a[i].s;
            f[j] = max(f[j], f[pre] + a[i].e - pre * a[i].l);
        }
    }
    int res = 0;
    for (int j = 0; j <= m; ++j) res = max(res, f[j]);
    cout << res << endl;
}

int main() {
    int T = 1, t = 1;
    cin >> T;
    while (T--) {
        cout << "Case #" << t++ << ": ";
        solve();
    }
    return 0;
}
