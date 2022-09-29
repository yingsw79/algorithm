#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int, int> f;
        int res = 0;
        for (auto& x : arr) {
            if (f.count(x - d))
                f[x] = f[x - d] + 1;  //只有一条转移途径
            else
                f[x] = 1;
            res = max(res, f[x]);
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}