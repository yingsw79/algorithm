#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/description/312/

/* 
求第k大的数，可以转化为二分枚举区间[1,n]的右边界n，看[1,n]的满足要求的数，由于其随区间变大而单调增，
所以是二分。通过不断调整，可以找到最小n使得区间[1,n]恰有k个满足要求的数。但是二分的话会让复杂度多一个log 
*/

const int N = 15;
int nums[N];
int f[N][N][2];  //标记此时是否已有连续3个6的m也必须记忆化,两种状态是不同的

int dfs(int pos, int cnt, int m, bool isLimit, bool isNum) {
    if (cnt >= 3) m = 1;
    if (!pos) return isNum && m;
    if (!isLimit && isNum && f[pos][cnt][m] != -1) return f[pos][cnt][m];
    int res = 0;
    if (!isNum) res = dfs(pos - 1, cnt, m, false, false);
    for (int i = 1 - isNum, up = isLimit ? nums[pos] : 9; i <= up; i++) {
        int t = i == 6 ? cnt + 1 : 0;
        res += dfs(pos - 1, t, m, isLimit && i == nums[pos], true);
    }
    if (!isLimit && isNum) f[pos][cnt][m] = res;
    return res;
}

int calc(LL x) {
    memset(f, -1, sizeof f);
    int n = 0;
    while (x) nums[++n] = x % 10, x /= 10;
    return dfs(n, 0, 0, true, false);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int k;
        scanf("%d", &k);
        LL l = 0, r = 1e10;
        while (l < r) {
            LL mid = l + r >> 1;
            if (calc(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        printf("%lld\n", l);
    }

    return 0;
}