#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<int> f(n);
        f[n - 1] = s[n - 1] - 'a';
        for (int i = n - 2; i >= 0; --i)  // 后缀最小值
            f[i] = min(s[i] - 'a', f[i + 1]);

        string res, tmp;
        for (int i = 0; i < n; ++i) {
            while (tmp.size() && tmp.back() - 'a' <= f[i]) {
                res.push_back(tmp.back());
                tmp.pop_back();
            }
            tmp.push_back(s[i]);
        }
        reverse(tmp.begin(), tmp.end());
        return res + tmp;
    }
};

int main() {
    

    return 0;
}