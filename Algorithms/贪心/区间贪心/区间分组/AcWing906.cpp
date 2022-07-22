#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 100010;
PII q[N];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {l, r};
    }
    sort(q, q + n);
    for (int i = 0; i < n; i++) {
        auto [l, r] = q[i];
        if (pq.empty() || pq.top() >= l)
            pq.push(r);
        else
            pq.pop(), pq.push(r);
    }
    cout << (int)pq.size() << endl;

    return 0;
}