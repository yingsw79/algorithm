#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int> &nums) {
        int ans = 0, mx = *max_element(nums.begin(), nums.end());
        bool has[mx + 1];
        memset(has, 0, sizeof(has));
        for (int x : nums) has[x] = true;
        for (int i = 1; i <= mx; ++i) {
            int g = 0;                                  // 0 和任何数 x 的最大公约数都是 x
            for (int j = i; j <= mx && g != i; j += i)  // 枚举 i 的倍数 j
                if (has[j])                             // 如果 j 在 nums 中
                    g = gcd(g, j);                      // 更新最大公约数
            if (g == i) ++ans;                          // 找到一个答案
        }
        return ans;
    }
};

int main() {
    return 0;
}