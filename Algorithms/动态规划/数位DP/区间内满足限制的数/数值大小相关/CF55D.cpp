#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://codeforces.com/problemset/problem/55/D
// https://www.luogu.com.cn/problem/CF55D
// http://www.manongjc.com/detail/15-kdhlhjscdvcarhp.html

// 对于满足同一个条件的多组询问,则我们上次记忆化的f数组依旧能用于下一次,所以f数组只需要初始化一次，

const int P = 2520;  //1~9的lcm
LL f[20][2550][50];
int nums[20], idx[2550];  //离散化lcm

LL dfs(int pos, int val, int _lcm, bool isLimit, bool isNum) {
    if (!pos) return isNum && val % _lcm == 0;
    if (!isLimit && isNum && f[pos][val][idx[_lcm]] != -1) return f[pos][val][idx[_lcm]];
    LL res = 0;
    if (!isNum) res = dfs(pos - 1, val, _lcm, false, false);
    for (int i = 1 - isNum, up = isLimit ? nums[pos] : 9; i <= up; i++) {
        int t = i ? lcm(_lcm, i) : _lcm;
        res += dfs(pos - 1, (val * 10 + i) % P, t, isLimit && i == nums[pos], true);
    }
    if (!isLimit && isNum) f[pos][val][idx[_lcm]] = res;
    return res;
}

void init() {
    memset(f, -1, sizeof f);  //本题只用初始化一次
    int k = 0;
    for (int i = 1; i <= P; i++) {
        if (P % i == 0) idx[i] = k++;
    }
}

LL calc(LL x) {
    int n = 0;
    while (x) nums[++n] = x % 10, x /= 10;
    return dfs(n, 0, 1, true, false);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    init();
    LL l, r;
    while (T--) {
        cin >> l >> r;
        cout << calc(r) - calc(l - 1) << endl;
    }

    return 0;
}