#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-cost-to-split-an-array/

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        int f[n + 1], cnt[n];
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            memset(cnt, 0, sizeof cnt);
            int t = 0;
            f[i] = INT_MAX;
            for (int j = i; j; j--) {
                int x = nums[j - 1];
                if (cnt[x] == 1)
                    t += 2;
                else if (cnt[x] > 1)
                    t++;
                cnt[x]++;
                f[i] = min(f[i], f[j - 1] + t + k);
            }
        }
        return f[n];
    }
};

int main() {
    return 0;
}