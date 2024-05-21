#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/set-intersection-size-at-least-two/

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1] || a[1] == b[1] && a[0] > b[0];
        });
        int last1 = -1, last2 = -1;
        int res = 0;
        for (auto& q : intervals) {
            if (q[0] > last2) {
                last1 = q[1] - 1, last2 = q[1];
                res += 2;
            } else if (q[0] > last1) {
                last1 = last2, last2 = q[1];
                res++;
            }
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}