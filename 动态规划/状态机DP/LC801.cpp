#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing/

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int f[n][2];  // 是否翻转
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0, f[0][1] = 1;
        for (int i = 1; i < n; ++i) {
            if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) {
                f[i][0] = min(f[i][0], f[i - 1][0]);
                f[i][1] = min(f[i][1], f[i - 1][1] + 1);
            }
            if (nums2[i - 1] < nums1[i] && nums1[i - 1] < nums2[i]) {
                f[i][0] = min(f[i][0], f[i - 1][1]);
                f[i][1] = min(f[i][1], f[i - 1][0] + 1);
            }
        }
        return min(f[n - 1][0], f[n - 1][1]);
    }
};

int main() {
    return 0;
}