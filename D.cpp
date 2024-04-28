// Problem D:----   The Galactic Message Decoder Ring

#include <bits/stdc++.h>
using namespace std;

const int N = 4e6 + 5;
char s[N];
bool pre[N], suf[N];
int mx[N], n, sum[N];

void work(bool dp[N]) {
    int p = 0;

    for (int i = 1; i <= n; ++i) {
        int l = 0;

        if (p + mx[p] - 1 >= i) {
            l = min({mx[2 * p - 1 - i + 1], p + mx[p] - i});
        }

        while (l < i - 1 && i + l - 1 < n && s[i - l - 1] == s[i + l])
            ++l;

        mx[i] = l;

        if (i + mx[i] > p + mx[p])
            p = i;
    }

    dp[0] = sum[1] = 1;

    for (int i = 1; i < n; ++i) {
        int l = mx[i + 1];
        dp[i] = sum[i - l] != sum[i];
        sum[i + 1] = sum[i] + dp[i];
    }
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    work(pre);
    reverse(s + 1, s + n + 1);
    work(suf);
    reverse(suf + 1, suf + n + 1);
    int p = 0;
    int ans = 0;

    for (int i = 1; i < n; ++i) {
        if (suf[i + 1])
            ans = max(ans, p + n - i);

        if (pre[i])
            p = max(p, i), ans = max(ans, i);
    }

    cout << n - ans << endl;
    return 0;
}