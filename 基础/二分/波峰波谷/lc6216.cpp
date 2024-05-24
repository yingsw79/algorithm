#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/contest/weekly-contest-316/problems/minimum-cost-to-make-array-equal/

class Solution {
public:
    typedef long long LL;
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        auto check = [&](int x) -> LL {
            LL res = 0;
            for (int i = 0; i < n; ++i)
                res += (LL)cost[i] * abs(nums[i] - x);
            return res;
        };
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid) <= check(mid + 1))
                r = mid;
            else
                l = mid + 1;
        }
        return check(l);
    }
};

int main() {
    

    return 0;
}