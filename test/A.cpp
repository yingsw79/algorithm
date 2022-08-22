#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int N = 200010;
int a[N];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n, [](auto& x, auto& y) {
        string c = to_string(x), d = to_string(y);
        return c + d > d + c;
    });
    string res = "";
    for (int i = 1; i <= 3; i++) res += to_string(a[i]);
    cout << res << endl;

    return 0;
}