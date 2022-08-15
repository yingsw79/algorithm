#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/1084/

const int N = 35;
int f[N][N];
int l, r, n;
string s;

int dp(int pos, int pre, bool isLimit, bool isNum) {
    if (pos == n) return isNum;
    if (!isLimit && isNum && f[pos][pre] != -1) return f[pos][pre];
    int res = 0;
    if (!isNum) res = dp(pos + 1, pre, false, false);
    for (int i = 1 - isNum, up = isLimit ? s[pos] - '0' : 9; i <= up; i++) {
        if (i < pre) continue;
        res += dp(pos + 1, i, isLimit && i == up, true);
    }
    if (!isLimit && isNum) f[pos][pre] = res;
    return res;
}

int calc(int x) {
    memset(f, -1, sizeof f);
    s = to_string(x);  //只有10进制可以直接这么做
    n = s.length();
    return dp(0, -2, true, false);
}

int main() {
    while (cin >> l >> r) {
        cout << calc(r) - calc(l - 1) << endl;
    }

    return 0;
}