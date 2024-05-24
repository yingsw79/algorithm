#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/longest-uploaded-prefix/

class LUPrefix {
    vector<int> p;

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

public:
    LUPrefix(int n) {
        p.resize(n + 2);
        for (int i = 1; i < n + 2; ++i) p[i] = i;
    }

    void upload(int x) {
        p[x] = find(x + 1);
    }

    int longest() {
        return find(1) - 1;
    }
};

int main() {
    return 0;
}