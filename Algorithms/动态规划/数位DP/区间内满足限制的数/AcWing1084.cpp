#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/1086/

int f[35][110];
int l, r, n, p;
string s;

int dp(int pos, int sum, bool isLimit, bool isNum) {
    if (pos == n) return isNum && !sum;
    if (!isLimit && isNum && f[pos][sum] != -1) return f[pos][sum];
    int res = 0;
    if (!isNum) res = dp(pos + 1, sum, false, false);
    for (int i = 1 - isNum, up = isLimit ? s[pos] - '0' : 9; i <= up; i++) {
        res += dp(pos + 1, (sum + i) % p, isLimit && i == up, true);
    }
    if (!isLimit && isNum) f[pos][sum] = res;
    return res;
}

int calc(int x) {
    memset(f, -1, sizeof f);
    s = to_string(x);
    n = s.length();
    return dp(0, 0, true, false);
}

int main() {
    while (cin >> l >> r >> p) {
        cout << calc(r) - calc(l - 1) << endl;
    }

    return 0;
}