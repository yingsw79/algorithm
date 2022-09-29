#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/rotated-digits/

class Solution {
public:
    int f[6][2], nums[6];

    int dfs(int pos, bool flag, bool isLimit, bool isNum) {
        if (!pos) return isNum && flag;
        if (!isLimit && isNum && f[pos][flag] != -1) return f[pos][flag];
        int res = 0;
        if (!isNum) res = dfs(pos - 1, flag, false, false);
        for (int i = 1 - isNum, up = isLimit ? nums[pos] : 9; i <= up; ++i) {
            if (i == 3 || i == 4 || i == 7) continue;
            // if (i == 2 || i == 5 || i == 6 || i == 9) flag = true;
            res += dfs(pos - 1, flag || i == 2 || i == 5 || i == 6 || i == 9, isLimit && i == nums[pos], true);
        }
        if (!isLimit && isNum) f[pos][flag] = res;
        return res;
    }

    int rotatedDigits(int n) {
        memset(f, -1, sizeof f);
        int len = 0;
        while (n) nums[++len] = n % 10, n /= 10;
        return dfs(len, false, true, false);
    }
};

int main() {
    return 0;
}