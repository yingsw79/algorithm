#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimize-xor/

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            if (!cnt) break;
            if (num1 >> i & 1) {
                res |= 1 << i;
                cnt--;
            }
        }
        for (int i = 0; i <= 31; ++i) {
            if (!cnt) break;
            if (!(num1 >> i & 1)) {
                res |= 1 << i;
                cnt--;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}