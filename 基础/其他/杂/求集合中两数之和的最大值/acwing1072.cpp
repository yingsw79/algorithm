#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10010, M = N * 2;

int n;
int h[N], e[M], w[M], ne[M], idx;
int d[N], res;  //路径中可以只包含一个点

void add(int x, int y, int z) {
    e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

void dp(int x, int fa) {
    for (int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        dp(j, x);
        res = max(res, d[x] + d[j] + w[i]);
        d[x] = max(d[x], d[j] + w[i]);
    }
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dp(1, -1);
    cout << res << endl;

    return 0;
}