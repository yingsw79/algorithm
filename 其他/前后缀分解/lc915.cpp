#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/partition-array-into-disjoint-intervals/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxL(n), minR(n);
        maxL[0] = nums[0], minR[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i) maxL[i] = max(maxL[i - 1], nums[i]);
        for (int i = n - 2; i >= 0; --i) minR[i] = min(minR[i + 1], nums[i]);
        for (int i = 0; i < n - 1; ++i) {
            if (maxL[i] <= minR[i + 1]) return i + 1;
        }
        return -1;
    }
};

int main() {
    return 0;
}