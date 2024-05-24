#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/construct-smallest-number-from-di-string/

class Solution {
public:
    string smallestNumber(string s) {
        int n = s.length();
        vector<int> indeg(n + 1), tmp(n + 1);
        vector<vector<int>> g(n + 1);
        priority_queue<int, vector<int>, greater<int>> pq;  //字典序最小拓扑序
        int idx = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                g[i].push_back(i + 1);
                indeg[i + 1]++;
            } else {
                g[i + 1].push_back(i);
                indeg[i]++;
            }
        }
        for (int i = 0; i < n + 1; i++) {
            if (!indeg[i]) pq.push(i);
        }
        while (!pq.empty()) {
            int t = pq.top();
            pq.pop();
            tmp[t] = idx++;  //从小到大依次编号
            for (auto x : g[t]) {
                if (--indeg[x] == 0) pq.push(x);
            }
        }
        string res;
        for (auto x : tmp) res += to_string(x);
        return res;
    }
};

int main() {
    

    system("pause");
    return 0;
}