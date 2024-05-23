#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimize-manhattan-distances/description/

class Solution {
public:
    int minimumDistance(vector<vector<int>> &points) {
        multiset<int> xs, ys;
        for (auto &p : points) {
            xs.insert(p[0] + p[1]);
            ys.insert(p[1] - p[0]);
        }
        int res = INT_MAX;
        for (auto &p : points) {
            int x = p[0] + p[1], y = p[1] - p[0];
            xs.erase(xs.find(x));
            ys.erase(ys.find(y));
            res = min(res, max(*xs.rbegin() - *xs.begin(), *ys.rbegin() - *ys.begin()));
            xs.insert(x);
            ys.insert(y);
        }
        return res;
    }
};

int main() {
    return 0;
}