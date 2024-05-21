#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 10000007;

// https://www.luogu.com.cn/problem/P4317
// 对于满足同一个条件的多组询问,则我们上次记忆化的f数组依旧能用于下一次,所以f数组只需要初始化一次，
// 而本题每次数位DP满足的条件都不一样,所以我们每次都需要重新初始化f数组

const int N = 55;
LL f[N][N];
int nums[N];

LL dfs(int pos, int cnt, int k, bool isLimit, bool isNum) {
    if (!pos) return isNum && cnt == k;
    if (!isLimit && isNum && f[pos][cnt] != -1) return f[pos][cnt];
    LL res = 0;
    if (!isNum) res = dfs(pos - 1, cnt, k, false, false);
    for (int i = 1 - isNum, up = isLimit ? nums[pos] : 1; i <= up; i++) {
        if (cnt + i > k) continue;
        res += dfs(pos - 1, cnt + i, k, isLimit && i == nums[pos], true);
    }
    if (!isLimit && isNum) f[pos][cnt] = res;
    return res;
}

LL qmul(LL a, LL b, int p) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int calc(LL x) {
    int n = 0;
    while (x) nums[++n] = x & 1, x >>= 1;
    int res = 1;
    for (int i = 1; i <= n; i++) {
        memset(f, -1, sizeof f);
        res = res * qmul(i, dfs(n, 0, i, true, false), MOD) % MOD;
    }
    return res;
}

int main() {
    LL n;
    cin >> n;
    cout << calc(n) << endl;

    return 0;
}