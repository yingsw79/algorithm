#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/description/1252/

const int N = 40010;
int p[N];
int n, m;

int get(int x, int y) {
    return x * n + y;
}

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n * n; i++) p[i] = i;

    int res = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        char d;
        cin >> x >> y >> d;
        x--, y--;
        int a = get(x, y), b;
        if (d == 'D')
            b = get(x + 1, y);
        else
            b = get(x, y + 1);

        a = find(a), b = find(b);
        if (a == b) {
            res = i;
            break;
        }
        p[a] = b;
    }

    if (!res)
        puts("draw");
    else
        cout << res << endl;

    return 0;
}
