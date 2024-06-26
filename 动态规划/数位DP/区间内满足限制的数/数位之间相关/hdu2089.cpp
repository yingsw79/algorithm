#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// http://acm.hdu.edu.cn/showproblem.php?pid=2089

const int N = 15;
int f[N][N];
int l, r, n;
string s;

int dp(int pos, int pre, int isLimit, int isNum) {
    if (pos == n) return isNum;
    if (!isLimit && isNum && f[pos][pre] != -1) return f[pos][pre];
    int res = 0;
    if (!isNum) res = dp(pos + 1, pre, 0, 0);                                 //从下一位开始选
    for (int i = 1 - isNum, up = isLimit ? s[pos] - '0' : 9; i <= up; i++) {  //必须从这位开始选,不能选零
        if (i == 4 || pre == 6 && i == 2) continue;                           //因为选零相当于没选,即从下一位开始选,而上面以及包括这种情况了
        res += dp(pos + 1, i, isLimit && i == up, 1);
    }
    if (!isLimit && isNum) f[pos][pre] = res;
    return res;
}

int calc(int x) {
    memset(f, -1, sizeof f);
    s = to_string(x);
    n = s.length();
    return dp(0, 0, 1, 0);
}

int main() {
    while (cin >> l >> r, l || r) {
        cout << calc(r) - calc(l - 1) << endl;
    }

    return 0;
}