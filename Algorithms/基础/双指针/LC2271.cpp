#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-white-tiles-covered-by-a-carpet/

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end(), [](auto &a, auto &b) { return a[0] < b[0]; });
        int ans = 0, cover = 0, left = 0;
        for (auto &t : tiles) {
            int tl = t[0], tr = t[1];
            cover += tr - tl + 1;
            for (; tiles[left][1] + carpetLen - 1 < tr; ++left)
                cover -= tiles[left][1] - tiles[left][0] + 1;
            ans = max(ans, cover - max(tr - carpetLen + 1 - tiles[left][0], 0));  // 0 表示毯子左端点不在瓷砖内的情况
        }
        return ans;
    }
};

int main() {
    

    return 0;
}