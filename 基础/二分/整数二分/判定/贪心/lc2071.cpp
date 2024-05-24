#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());
        
        auto check = [&](int mid) -> bool {
            int p = pills;
            deque<int> dq;
            int j = 0;
            for (int i = mid - 1; i >= 0; i--) {
                for (; j <= mid - 1 && workers[j] + strength >= tasks[i]; j++)
                    dq.push_front(workers[j]);
                if (dq.empty())
                    return false;
                else if (dq.back() >= tasks[i])
                    dq.pop_back();
                else if (!p)
                    return false;
                else
                    dq.pop_front(), --p;
            }
            return true;
        };

        int l = 0, r = min(m, n);
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto check = [&](int mid) -> bool {
            int p = pills;
            // 工人的有序集合
            multiset<int> ws;
            for (int i = m - mid; i < m; ++i) {
                ws.insert(workers[i]);
            }
            // 从大到小枚举每一个任务
            for (int i = mid - 1; i >= 0; --i) {
                // 如果有序集合中最大的元素大于等于 tasks[i]
                if (auto it = prev(ws.end()); *it >= tasks[i]) {
                    ws.erase(it);
                } else {
                    if (!p) {
                        return false;
                    }
                    auto rep = ws.lower_bound(tasks[i] - strength);
                    if (rep == ws.end()) {
                        return false;
                    }
                    --p;
                    ws.erase(rep);
                }
            }
            return true;
        };

        int l = 0, r = min(m, n);
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

int main() {
    system("pause");
    return 0;
}