#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/

class Solution {
public:
    using ULL = unsigned long long;

    ULL get(vector<ULL>& h, vector<ULL>& p, int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<int> f(n + 1);
        vector<ULL> h1(n + 1), h2(n + 1), p(n + 1);
        p[0] = 1;
        for (int i = 1, j = n - 1; i <= n; i++, j--) {
            h1[i] = h1[i - 1] * 131 + s[i - 1];
            h2[i] = h2[i - 1] * 131 + s[j];
            p[i] = p[i - 1] * 131;
        }
        for (int i = k; i <= n; ++i) {
            f[i] = f[i - 1];
            for (int j = i - k + 1; j; --j) {
                if (get(h1, p, j, i) == get(h2, p, n + 1 - i, n + 1 - j)) {
                    f[i] = max(f[i], f[j - 1] + 1);
                    break;
                }
            }
        }
        return f[n];
    }
};

int main() {
    return 0;
}