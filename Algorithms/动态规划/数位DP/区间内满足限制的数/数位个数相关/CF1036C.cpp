#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://codeforces.com/contest/1036/problem/C
// https://www.luogu.com.cn/problem/CF1036C

const int N = 20;
LL f[N][N];
int nums[N];

LL dfs(int pos, int cnt, bool isLimit, bool isNum) {
    if (!pos) return isNum;
    if (!isLimit && isNum && f[pos][cnt] != -1) return f[pos][cnt];
    LL res = 0;
    if (!isNum) res = dfs(pos - 1, cnt, false, false);
    for (int i = 1 - isNum, up = isLimit ? nums[pos] : 9; i <= up; i++) {
        if (cnt + (i != 0) > 3) continue;
        res += dfs(pos - 1, cnt + (i != 0), isLimit && i == nums[pos], true);
    }
    if (!isLimit && isNum) f[pos][cnt] = res;
    return res;
}

LL calc(LL x) {
    memset(f, -1, sizeof f);
    int n = 0;
    while (x) nums[++n] = x % 10, x /= 10;
    return dfs(n, 0, true, false);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL l, r;
        cin >> l >> r;
        cout << calc(r) - calc(l - 1) << endl;
    }

    return 0;
}