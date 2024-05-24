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
        vector<vector<int>> res{intervals[0]};
        for (auto& interval : intervals) {
            auto& t = res.back();
            if (interval[0] > t[1]) {
                res.push_back(move(interval));
            } else if (interval[1] > t[1]) {
                t[1] = interval[1];
            }
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}