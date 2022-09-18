#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or/
// 区间可重复贡献问题:区间按位或
// st表+二分
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size(), t = log(n) / log(2) + 1;
        vector<vector<int>> f(n + 1, vector<int>(t));
        for (int i = 1; i <= n; ++i) f[i][0] = nums[i - 1];
        for (int j = 1; j < t; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; ++i)
                f[i][j] = f[i][j - 1] | f[i + (1 << j - 1)][j - 1];

        auto query = [&](int l, int r) {
            int k = log(r - l + 1) / log(2);
            return f[l][k] | f[r - (1 << k) + 1][k];
        };

        vector<int> res(n);
        for (int i = 1; i <= n; ++i) {
            int mx = query(i, n);
            int l = i, r = n;
            while (l < r) {
                int mid = l + r >> 1;
                if (query(i, mid) == mx)
                    r = mid;
                else
                    l = mid + 1;
            }
            res[i - 1] = l - i + 1;
        }
        return res;
    }
};

int main() {
    return 0;
}