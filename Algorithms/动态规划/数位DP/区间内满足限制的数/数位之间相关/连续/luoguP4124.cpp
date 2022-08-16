#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P4124

LL f[13][11][11][3][3][3];
int nums[13];

LL dfs(int pos, int pre1, int pre2, bool st, bool four, bool eight, bool isLimit, bool isNum) {
    if (four && eight) return 0;
    if (!pos) return isNum && st;
    if (!isLimit && isNum && f[pos][pre1][pre2][st][four][eight] != -1) return f[pos][pre1][pre2][st][four][eight];
    LL res = 0;
    if (!isNum) res = dfs(pos - 1, pre1, pre2, st, four, eight, false, false);
    for (int i = 1 - isNum, up = isLimit ? nums[pos] : 9; i <= up; i++) {
        res += dfs(pos - 1, i, pre1, st || i == pre1 && i == pre2, four || i == 4, eight || i == 8, isLimit && i == nums[pos], true);
    }
    if (!isLimit && isNum) f[pos][pre1][pre2][st][four][eight] = res;
    return res;
}

LL calc(LL x) {
    memset(f, -1, sizeof f);
    int n = 0;
    while (x) nums[++n] = x % 10, x /= 10;
    return dfs(n, -1, -1, false, false, false, true, false);
}

int main() {
    LL l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << endl;

    return 0;
}