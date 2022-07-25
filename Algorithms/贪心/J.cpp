#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 100010;
int a[N];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int res = 1 + a[1];
    for (int i = 2; i <= res; i++) {
        res = max(res, i + a[i]);
        if (i > n) {
            break;
        }
    }
    cout << res << endl;
    // system("pause");
    return 0;
}