#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/course-schedule-iii/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int tot = 0;
        for (auto& c : courses) {
            tot += c[0];
            pq.push(c[0]);
            if (tot > c[1]) {
                tot -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};

int main() {
    return 0;
}