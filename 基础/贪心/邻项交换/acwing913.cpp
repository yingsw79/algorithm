#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int t[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &t[i]);

    sort(t + 1, t + n + 1);

    LL res = 0;
    for (int i = 1; i <= n; i++) res += t[i] * (n - i);

    printf("%lld\n", res);

    return 0;
}
