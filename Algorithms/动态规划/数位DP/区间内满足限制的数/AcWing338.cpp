#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/description/340/

const int N = 15;
int f[N][N], nums[N];
int l, r, n;

int dp(int pos, int cnt, int num, bool isLimit, bool isNum) {
    if (!pos) return cnt;
    if (!isLimit && isNum && f[pos][cnt] != -1) return f[pos][cnt];
    int res = 0;
    if (!isNum) res = dp(pos - 1, cnt, num, false, false);
    for (int i = 1 - isNum, up = isLimit ? nums[pos] : 9; i <= up; i++) {
        res += dp(pos - 1, cnt + (i == num), num, isLimit && i == nums[pos], true);
    }
    if (!isLimit && isNum) f[pos][cnt] = res;
    return res;
}

int calc(int x, int num) {  //每个数字单独计算一次
    memset(f, -1, sizeof f);
    n = 0;
    while (x) nums[++n] = x % 10, x /= 10;
    return dp(n, 0, num, true, false);
}

int main() {
    while (cin >> l >> r, l || r) {
        if (l > r) swap(l, r);
        for (int i = 0; i <= 9; i++) cout << calc(r, i) - calc(l - 1, i) << " ";
        cout << endl;
    }

    return 0;
}