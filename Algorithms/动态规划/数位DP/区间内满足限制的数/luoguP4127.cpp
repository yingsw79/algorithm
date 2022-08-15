#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/description/313/
// https://www.luogu.com.cn/problem/P4127

LL f[20][200][200];
int p, nums[20];

LL dfs(int pos, int sum, int val, bool isLimit, bool isNum) {
    if (sum + pos * 9 < p) return 0;  //剪枝
    if (!pos) return isNum && sum == p && !val;
    if (!isLimit && isNum && f[pos][sum][val] != -1) return f[pos][sum][val];
    LL res = 0;
    if (!isNum) res = dfs(pos - 1, sum, val, false, false);
    for (int i = 1 - isNum, up = isLimit ? nums[pos] : 9; i <= up; i++) {
        if (sum + i > p) continue;  //剪枝
        res += dfs(pos - 1, sum + i, (val * 10 + i) % p, isLimit && i == nums[pos], true);
    }
    if (!isLimit && isNum) f[pos][sum][val] = res;
    return res;
}

LL calc(LL x) {
    int n = 0;
    LL res = 0;
    while (x) nums[++n] = x % 10, x /= 10;
    for (p = 1; p <= n * 9; p++) {
        memset(f, -1, sizeof f);
        res += dfs(n, 0, 0, true, false);
    }
    return res;
}

int main() {
    LL l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << endl;

    return 0;
}