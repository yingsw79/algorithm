#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-cost-to-make-array-equalindromic/description/

vector<int> pal;

auto init = [] {
    pal.push_back(0);  // 最小回文

    for (int base = 1; base <= 10000; base *= 10) {
        // 生成奇数长度回文数
        for (int i = base; i < base * 10; i++) {
            int x = i;
            for (int t = i / 10; t; t /= 10) {
                x = x * 10 + t % 10;
            }
            pal.push_back(x);
        }
        // 生成偶数长度回文数
        if (base <= 1000) {
            for (int i = base; i < base * 10; i++) {
                int x = i;
                for (int t = i; t; t /= 10) {
                    x = x * 10 + t % 10;
                }
                pal.push_back(x);
            }
        }
    }
    pal.push_back(1'000'000'001);  // 最大回文
    return 0;
}();

class Solution {
public:
    long long minimumCost(vector<int> &nums) {
        int m = (nums.size() - 1) / 2;
        nth_element(nums.begin(), nums.begin() + m, nums.end());
        int mid = nums[m];  // 靠左的中位数

        auto cost = [&](int i) -> long long {
            int target = pal[i];
            long long sum = 0;
            for (int x : nums) {
                sum += abs(x - target);
            }
            return sum;
        };

        int i = lower_bound(pal.begin(), pal.end(), mid) - pal.begin();

        return min(cost(i - 1), cost(i));
    }
};

int main() {
    return 0;
}