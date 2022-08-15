#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/1083/

const int N = 35;
int f[N][N], nums[N];
int l, r, n, k, B;

int dp(int pos, int cnt, bool isLimit, bool isNum) {
    if (!pos) return isNum && cnt == k;
    if (!isLimit && isNum && f[pos][cnt] != -1) return f[pos][cnt];
    int res = 0;
    if (!isNum) res = dp(pos - 1, cnt, false, false);
    for (int i = 1 - isNum, up = isLimit ? min(nums[pos], 1) : 1; i <= up; i++) {
        if (cnt + i > k) continue;
        res += dp(pos - 1, cnt + i, isLimit && i == nums[pos], true);  //注意i == nums[pos]
    }
    if (!isLimit && isNum) f[pos][cnt] = res;
    return res;
}

int calc(int x) {
    memset(f, -1, sizeof f);
    n = 0;
    while (x) nums[++n] = x % B, x /= B;  //B进制
    return dp(n, 0, true, false);  //从高位开始搜
}

int main() {
    cin >> l >> r >> k >> B;
    cout << calc(r) - calc(l - 1) << endl;

    return 0;
}