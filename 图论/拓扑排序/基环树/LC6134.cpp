#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/

class Solution {
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        int n = edges.size(), min_dis = n, ans = -1;
        auto calc_dis = [&](int x) -> vector<int> {
            vector<int> dis(n, n);
            for (int d = 0; x >= 0 && dis[x] == n; x = edges[x])
                dis[x] = d++;
            return dis;
        };
        auto d1 = calc_dis(node1), d2 = calc_dis(node2);
        for (int i = 0; i < n; ++i) {
            int d = max(d1[i], d2[i]);
            if (d < min_dis) {
                min_dis = d;
                ans = i;
            }
        }
        return ans;
    }
};

int main() {
    system("pause");
    return 0;
}