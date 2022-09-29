#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/number-of-good-paths/

class Solution {
public:
    vector<int> p;

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<int> idx(n);
        vector<vector<int>> g(n);
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i, idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return vals[a] < vals[b];
        });
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            while (j < n && vals[idx[j]] == vals[idx[i]]) j++;
            for (int k = i; k < j; ++k) {
                int y = idx[k];
                for (int x : g[y])
                    if (vals[x] <= vals[y]) p[find(x)] = find(y);
            }
            unordered_map<int, int> mp;
            for (int k = i; k < j; ++k) ++mp[find(idx[k])];
            for (auto& [_, v] : mp) res += v * (v + 1) / 2;
            i = j - 1;
        }
        return res;
    }
};

int main() {
    return 0;
}