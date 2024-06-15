#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 100010;
PII q[N];

// https://www.acwing.com/problem/content/description/910/

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        q[i] = {a, b};
    }

    sort(q, q + n, [](const PII& p1, const PII& p2) {
        return p1.second < p2.second;
    });

    int res = 0, last = -INF;
    for (int i = 0; i < n; i++) {
        auto& [l, r] = q[i];
        if (l > last) {
            res++;
            last = r;
        }
    }
    cout << res << endl;

    return 0;
}