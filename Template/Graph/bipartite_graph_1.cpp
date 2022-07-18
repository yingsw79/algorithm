#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;
int n, m, h[N], e[M], ne[M], idx, cl[N];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool dfs(int u, int c) {
    cl[u] = c;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!cl[j] && !dfs(j, 3 - c) || cl[j] == c) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    memset(h, -1, sizeof h);

    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!cl[i] && !dfs(i, 1)) {
            flag = false;
            break;
        }
    }

    cout << (flag ? "Yes" : "No") << '\n';
}
