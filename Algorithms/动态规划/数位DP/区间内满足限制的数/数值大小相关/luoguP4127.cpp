#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/description/313/
// https://www.luogu.com.cn/problem/P4127

// 对于满足同一个条件的多组询问,则我们上次记忆化的f数组依旧能用于下一次,所以f数组只需要初始化一次，
// 而本题每次数位DP满足的条件都不一样,所以我们每次都需要重新初始化f数组

LL f[20][200][200];
int p, nums[20];

LL dfs(int pos, int sum, int val, bool isLimit, bool isNum) {  //val必须边算边取余数,不然数组存不下
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
    for (p = 1; p <= n * 9; p++) {  //直接枚举所有可能的数字和,然后加起来
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