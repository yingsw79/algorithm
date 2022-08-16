#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/count-special-integers/

class Solution {
public:
    int countSpecialNumbers(int n) {
        auto s = to_string(n);
        int m = s.length(), dp[m][1 << 10];  //不贴上界,状态压缩
        memset(dp, -1, sizeof(dp));
        //当 isLimit == true 和 isNum == false 的时候不会重复搜索(!isLimit && isNum),不用记忆化
        //只需要记忆化 i 和 mask 
        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool isLimit, bool isNum) -> int {
            if (i == m) return isNum;
            if (!isLimit && isNum && dp[i][mask] >= 0) return dp[i][mask];
            int res = 0;
            if (!isNum) res = f(i + 1, mask, false, false);                       // 可以跳过当前数位
            for (int d = 1 - isNum, up = isLimit ? s[i] - '0' : 9; d <= up; ++d)  // 枚举要填入的数字 d
                if ((mask >> d & 1) == 0)                                         // d 不在 mask 中
                    res += f(i + 1, mask | (1 << d), isLimit && d == up, true);
            if (!isLimit && isNum) dp[i][mask] = res;
            return res;
        };
        return f(0, 0, true, false);
    }
};

int main() {
    system("pause");
    return 0;
}