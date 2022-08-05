#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) pq.push(nums[i]);
        }
        int res = 0;
        while (!pq.empty()) {
            int t = pq.top();
            pq.pop();
            queue<int> q;
            res++;
            while (!pq.empty()) {
                q.push(pq.top());
                pq.pop();
            }
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (cur - t != 0) {
                    pq.push(cur - t);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int k = 0, sum = 0;
        while (sum <= n) {
            sum += k + 1;
            if (sum > n)
                break;
            else
                k++;
        }
        return k;
    }
};

class Solution {
public:
    static const int N = 100010, INF = 0x3f3f3f3f;
    int dist1[N], dist2[N];
    vector<vector<int>> g;

    void bfs(int u, int* dist) {
        queue<int> q;
        q.push(u);
        dist[u] = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto& v : g[t]) {
                if (dist[v] > dist[t] + 1) {
                    dist[v] = dist[t] + 1;
                    q.push(v);
                }
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int INF = 0x3f3f3f3f;
        int n = edges.size();
        g.resize(n);
        memset(dist1, 0x3f, sizeof dist1);
        memset(dist2, 0x3f, sizeof dist2);

        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) g[i].push_back(edges[i]);
        }

        bfs(node1, dist1);
        bfs(node2, dist2);
        int res = -1, d = INF;
        for (int i = 0; i < n; i++) {
            int maxd = max(dist1[i], dist2[i]);
            if (d > maxd) {
                d = maxd;
                res = i;
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indeg(n);
        vector<bool> st(n);
        for (int i = 0; i < n; i++) {
            int j = edges[i];
            if (j != -1) {
                indeg[j]++;
            }
        }

        vector<int> q(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            if (!indeg[i]) q[++r] = i;
        }
        while (l <= r) {
            int t = q[l++];
            int j = edges[t];
            if (j != -1 && --indeg[j] == 0) q[++r] = j;
        }

        function<int(int)> cnt = [&](int u) {
            st[u] = true;
            int k = 1, j = edges[u];
            while (j != -1 && !st[j]) {
                k++;
                j = edges[j];
            }
            return k;
        };

        int res = -1;
        for (int i = 0; i < n; i++) {
            if (indeg[i] && !st[i]) {
                res = max(res, cnt(i));
            }
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}