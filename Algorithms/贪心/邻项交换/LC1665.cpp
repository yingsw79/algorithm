#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks/

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
            int c = max(a[1], a[0] + b[1]), d = max(b[1], a[1] + b[0]);
            return c < d || c == d && a[1] < b[1];
        });
        int res = 0, cost = 0;
        for (auto& t : tasks) {  // 注意此处
            res = max(res, cost + t[1]);
            cost += t[0];
        }
        return res;
    }
};

int main() {
    return 0;
}