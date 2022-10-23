#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/

class Solution {
public:
    int findIntegers(int n) {
        int nums[35], f[35][3];
        
        
        int len = 0;
        while (n) nums[++len] = n & 1, n >>= 1;
        function<int(int, int, bool, bool)> dfs = [&](int pos, int cnt, bool isLimit, bool isNum) -> int {
            if (!pos) return isNum;
            if (!isLimit && isNum && f[pos][cnt] != -1) return f[pos][cnt];
            int res = 0;
            if (!isNum) res = dfs(pos - 1, cnt, false, false);
            for (int i = 1 - isNum, up = isLimit ? nums[pos] : 1; i <= up; ++i) {
                int t = i? cnt + 1 : 0;
                if (t > 1) continue;
                res += dfs(pos - 1, t, isLimit && i == nums[pos], true);
            }
            if (!isLimit && isNum) f[pos][cnt] = res;
            return res;
        };
        return dfs(len, 0, true, false) + 1;
    }
};

signed main() {
    system("pause");
    return 0;
}