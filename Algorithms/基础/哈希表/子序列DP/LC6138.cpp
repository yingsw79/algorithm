#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/longest-ideal-subsequence/

class Solution {
public:
    int longestIdealString(string s, int k) {
        // unordered_map<char, int> f;
        vector<int> f(26);
        int res = 1;
        for (auto ch : s) {
            ch -= 'a';
            int t = 1;
            for (int c = 0; c <= 25; c++) {  //枚举可能的前一个字母
                if (abs(c - ch) <= k)
                    t = max(t, f[c] + 1);
            }
            res = max(res, t);
            f[ch] = t;  //更新该字母的最大值
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}