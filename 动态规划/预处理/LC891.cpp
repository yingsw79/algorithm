#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/sum-of-subsequence-widths/

class Solution {
public:
    typedef long long LL;
    const int MOD = 1e9 + 7;
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int p[n];
        p[0] = 1;
        for (int i = 1; i < n; ++i) p[i] = p[i - 1] * 2 % MOD;
        int res = 0;
        for (int i = 0; i < n; ++i) res = (res + (LL)(p[i] - p[n - 1 - i]) * nums[i]) % MOD;
        return (res + MOD) % MOD;
    }
};

int main() {
    return 0;
}