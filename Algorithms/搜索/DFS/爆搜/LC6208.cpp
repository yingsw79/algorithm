#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/number-of-valid-clock-times/

class Solution {
public:
    int countTime(string time) {
        int n = time.length(), res = 0;
        function<void(int)> dfs = [&](int u) {
            if (u == n) {
                int a, b;
                sscanf(time.c_str(), "%d:%d", &a, &b);
                if (a >= 0 && a <= 23 && b >= 0 && b <= 59) res++;
                return;
            }
            if (time[u] == '?') {
                for (char c = '0'; c <= '9'; ++c) {
                    time[u] = c;
                    dfs(u + 1);
                    time[u] = '?';  // ！！！
                }
            } else
                dfs(u + 1);  // ！！！
        };
        dfs(0);
        return res;
    }
};

int main() {
    return 0;
}