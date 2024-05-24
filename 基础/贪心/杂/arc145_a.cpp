#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://atcoder.jp/contests/arc145/tasks/arc145_a

string s;
int n;

int main() {
    scanf("%d", &n);
    cin >> s;
    if (s[0] == 'A' && s[n - 1] == 'B' || n == 2 && s == "BA")
        puts("No");
    else
        puts("Yes");

    return 0;
}