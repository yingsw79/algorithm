#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/k-similar-strings/
// https://leetcode.cn/problems/couples-holding-hands/

class Solution {
public:
    int h(string& s1, string& s2) {
        int cnt = 0, n = s1.length();
        for (int i = 0; i < n; ++i)
            if (s1[i] != s2[i]) cnt++;
        return (cnt + 1) / 2;
    }

    bool dfs(int u, int depth, string& s1, string& s2) {
        if (!depth) return s1 == s2;
        if (h(s1, s2) > depth) return false;
        int n = s1.length();
        while (u < n && s1[u] == s2[u]) u++;
        for (int i = u + 1; i < n; ++i) {
            if (s1[i] != s2[i] && s1[i] == s2[u]) {
                swap(s1[u], s1[i]);
                if (dfs(u + 1, depth - 1, s1, s2)) return true;
                swap(s1[u], s1[i]);
            }
        }
        return false;
    }

    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        int depth = 1;
        while (!dfs(0, depth, s1, s2)) depth++;
        return depth;
    }
};

int main() {
    return 0;
}