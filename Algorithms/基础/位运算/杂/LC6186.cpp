#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or/

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(32, n), res(n);
        for (int i = n - 1; i >= 0; --i) {
            int t = i;
            for (int j = 0; j < 32; ++j) {
                if (nums[i] >> j & 1)
                    p[j] = i;
                else if (p[j] < n)
                    t = max(t, p[j]);
            }
            res[i] = t - i + 1;
        }
        return res;
    }
};

int main() {
    return 0;
}