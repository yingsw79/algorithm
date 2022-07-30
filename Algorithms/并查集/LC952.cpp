#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n), sz(n, 1);
        for (int i = 0; i < n; i++) p[i] = i;
        function<int(int)> find = [&](int x) -> int {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = 1; j <= x / j; j++) {
                if (x % j == 0) {
                    if (j > 1) mp[j].push_back(i);
                    if (j != x / j) mp[x / j].push_back(i);
                }
            }
        }
        int res = 1;
        for (auto& [_, v] : mp) {
            int a = find(v[0]);
            for (int i = 1; i < v.size(); i++) {
                int b = find(v[i]);
                if (a != b) {
                    p[b] = a;
                    sz[a] += sz[b];
                    res = max(res, sz[a]);
                }
            }
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}