#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-number-of-robots-within-budget/

class Solution {
public:
    typedef long long LL;
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        auto check = [&](int mid) -> bool {
            vector<int> q(n + 1);
            int hh = 0, tt = -1;
            LL sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += runningCosts[i];
                if (i > mid) sum -= runningCosts[i - mid];
                if (hh <= tt && i - q[hh] + 1 > mid) hh++;
                while (hh <= tt && chargeTimes[q[tt]] <= chargeTimes[i]) tt--;
                q[++tt] = i;
                if (i >= mid - 1 && chargeTimes[q[hh]] + mid * sum <= budget) return true;
            }
            return false;
        };
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

int main() {
    

    return 0;
}