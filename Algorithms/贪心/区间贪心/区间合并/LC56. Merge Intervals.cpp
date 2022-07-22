#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
// https://leetcode.cn/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto& interval : intervals) {
            if (res.empty() || interval[0] > res.back()[1]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}