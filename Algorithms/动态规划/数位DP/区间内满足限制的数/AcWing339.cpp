#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/341/

const int N = 35;  //int二进制最多32位
int f[N][N][N], nums[N];
int l, r, n;

int dp(int pos, int cnt0, int cnt1, bool isLimit, bool isNum) {
    if (!pos) return isNum && cnt0 >= cnt1;
    if (!isLimit && isNum && f[pos][cnt0][cnt1] != -1) return f[pos][cnt0][cnt1];
    int res = 0;
    if (!isNum) res = dp(pos - 1, cnt0, cnt1, false, false);
    for (int i = 1 - isNum, up = isLimit ? nums[pos] : 1; i <= up; i++) {
        res += dp(pos - 1, cnt0 + !i, cnt1 + i, isLimit && i == nums[pos], true);
    }
    if (!isLimit && isNum) f[pos][cnt0][cnt1] = res;
    return res;
}

int calc(int x) {
    memset(f, -1, sizeof f);
    n = 0;
    while (x) nums[++n] = x % 2, x /= 2;
    return dp(n, 0, 0, true, false);
}

signed main() {
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << endl;

    return 0;
}