#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-running-time-of-n-computers/

class Solution {
public:
    long long maxRunTime(int n, vector<int> &batteries) {
        long tot = accumulate(batteries.begin(), batteries.end(), 0L);
        long l = 0, r = tot / n;
        while (l < r) {
            long mid = l + r + 1 >> 1, sum = 0;
            for (long b : batteries)
                sum += min(b, mid);

            if (n * mid <= sum)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

class Solution {
public:
    long long maxRunTime(int n, vector<int> &batteries) {
        sort(batteries.begin(), batteries.end());
        long sum = accumulate(batteries.begin(), batteries.end(), 0L);
        for (int i = batteries.size() - 1;; --i) {
            if (batteries[i] <= sum / n) {
                return sum / n;
            }
            sum -= batteries[i];
            --n;
        }
    }
};

int main() {
    system("pause");
    return 0;
}