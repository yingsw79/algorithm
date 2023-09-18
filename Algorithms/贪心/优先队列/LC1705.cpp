#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-number-of-eaten-apples/

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size(), res = 0;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for (int i = 0; i < n || !pq.empty(); i++) {
            if (i < n && apples[i]) pq.emplace(i + days[i], apples[i]);
            while (!pq.empty() && pq.top().first <= i) pq.pop();
            if (!pq.empty()) {
                auto [x, y] = pq.top();
                pq.pop();
                if (y > 1) pq.emplace(x, y - 1);
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