#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;

int main() {
    int n, m, l, r;
    cin >> n >> m;
    vector<int> a(1001, -1), b(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        for (int j = l; j <= r; j++) {
            a[j] = i;
        }
    }
    for (int i = 0; i <= 1000; i++) {
        if (a[i] != -1) b[a[i]] = 1;
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += b[i];
    }
    LL res = pow(2, sum);
    cout << res << endl;

    return 0;
}