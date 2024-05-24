#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        auto check = [&](int mid) -> bool {
            int t = price[0], cnt = 1;
            for (int x : price) {
                if (x >= t + mid) {
                    cnt++;
                    t = x;
                }
            }
            return cnt >= k;
        };
        int l = 0, r = price.back() - price[0];
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