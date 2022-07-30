#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> cl(n);
        function<bool(int, int)> dfs = [&](int u, int c) {
            cl[u] = c;
            for (auto& v : graph[u]) {
                if (!cl[v] && !dfs(v, 3 - c) || cl[v] == c) return false;
            }
            return true;
        };
        for (int i = 0; i < n; i++) {
            if (!cl[i] && !dfs(i, 1)) return false;
        }
        return true;
    }
};

int main() {
    system("pause");
    return 0;
}