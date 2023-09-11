#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        const int N = 100010;
        vector<int> st[N];
        for (int i = 0; i < n; ++i) {
            st[events[i][0]].push_back(events[i][1]);  //预处理每天开始会议的结束时间
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        for (int i = 1; i < N; i++) {
            for (auto& ed : st[i]) {  //将第i天新增的可以参加会议的结束时间加入优先队列
                pq.push(ed);
            }
            while (!pq.empty() && pq.top() < i) pq.pop();  //将还在优先队列里但已不能参加的会议去除
            if (!pq.empty()) {  //每次选择参加结束时间最早的会议
                pq.pop();
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