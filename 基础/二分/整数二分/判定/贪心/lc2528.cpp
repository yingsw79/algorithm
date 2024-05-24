#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximize-the-minimum-powered-city/

class Solution {
public:
    typedef long long LL;
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<LL> diff(n);
        for (int i = 0; i < n; i++) {
            diff[max(i - r, 0)] += stations[i];
            if (i + r + 1 < n) diff[i + r + 1] -= stations[i];
        }

        auto check = [&](vector<LL> nums, LL mid) -> bool {
            int cnt = k;
            LL s = 0;
            for (int i = 0; i < n; i++) {
                s += nums[i];
                if (s >= mid) continue;
                if (s + cnt >= mid) {
                    int d = mid - s;
                    nums[i] += d;
                    if (i + r * 2 + 1 < n) nums[i + r * 2 + 1] -= d;
                    s = mid;
                    cnt -= d;
                } else
                    return false;
            }
            return true;
        };

        LL l = 0, h = 1e11;
        while (l < h) {
            LL mid = l + h + 1 >> 1;
            if (check(diff, mid))
                l = mid;
            else
                h = mid - 1;
        }
        return l;
    }
};

int main() {
    return 0;
}