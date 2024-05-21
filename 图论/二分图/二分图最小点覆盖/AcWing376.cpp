#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110, M = 1010;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];
int n, m, k;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x) {
    for (int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if (st[j]) continue;
        st[j] = true;
        if (!match[j] || find(match[j])) {
            match[j] = x;
            return true;
        }
    }
    return false;
}

int main() {
    while (cin >> n, n) {
        cin >> m >> k;
        idx = 0;
        memset(h, -1, sizeof h);
        memset(match, 0, sizeof match);

        while (k--) {
            int i, a, b;
            cin >> i >> a >> b;
            if (!a || !b) continue;
            add(a, b);
        }

        int res = 0;
        for (int i = 1; i < n; i++) {
            memset(st, 0, sizeof st);
            if (find(i)) res++;
        }

        cout << res << endl;
    }

    return 0;
}