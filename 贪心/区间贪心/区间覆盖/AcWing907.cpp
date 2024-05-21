#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 100010;
PII q[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int st, ed;
    cin >> st >> ed;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {l, r};
    }
    sort(q, q + n);
    int res = 0;
    bool flag = false;
    for (int i = 0; i < n;) {
        int j = i, r = -2e9;
        while (j < n && q[j].first <= st) {
            r = max(r, q[j].second);
            j++;
        }
        if (r < st) break;
        res++;
        if (r >= ed) {
            flag = true;
            break;
        }
        st = r;
        i = j;
    }
    cout << (flag ? res : -1) << endl;

    return 0;
}