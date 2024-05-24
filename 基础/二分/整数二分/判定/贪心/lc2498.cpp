#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/frog-jump-ii/

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        bool st[n];
        auto check1 = [&](int mid) -> bool {
            for (int i = 0; i < n;) {
                int j = i + 1;
                while (j < n && stones[j] - stones[i] <= mid) j++;
                int x = -1;
                for (int k = j - 1; k > i; k--) {
                    if (!st[k]) {
                        if (k == n - 1) return true;
                        st[k] = true;
                        x = k;
                        break;
                    }
                }
                if (x == -1) return false;
                i = x;
            }
            return false;
        };

        auto check2 = [&](int mid) -> bool {
            memset(st, 0, sizeof st);
            return check1(mid) && check1(mid);
        };

        int l = 0, r = stones[n - 1];
        while (l < r) {
            int mid = l + r >> 1;
            if (check2(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main() {
    return 0;
}