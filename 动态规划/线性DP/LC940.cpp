#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/distinct-subsequences-ii/

class Solution {
public:
    const int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        int f[26] = {0};
        for (auto c : s) {
            int x = c - 'a', t = 1;
            for (int i = 0; i < 26; ++i)
                t = (t + f[i]) % MOD;
            f[x] = t;
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) res = (res + f[i]) % MOD;
        return res;
    }
};

int main() {
    return 0;
}