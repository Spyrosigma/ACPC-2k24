// Problem A :--- The Mystery of the Forgotten City

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back

int n, m, Q;
int ans[1005][1005];
bool has[1005][1005][11];

bool ok(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
void solve() {
    scanf("%d%d%d", &n, &m, &Q);
    vector <pii > vec;
    memset(ans, -1, sizeof(ans));

    for (int _ = 0; _ < Q; _++) {
        int dx, dy;
        scanf("%d%d", &dx, &dy);
        vec.pb(mp(dx, dy));
        int k;
        scanf("%d", &k);
        queue <pii > q;

        while (q.size())
            q.pop();

        while (k--) {
            int x, y;
            scanf("%d%d", &x, &y);
            ans[x][y] = 1, has[x][y][_] = 1;

            if (ok(x - dx, y - dy))
                ans[x - dx][y - dy] = 0;
        }
    }

    queue <pii > q;

    while (q.size())
        q.pop();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (ans[i][j] == 1)
                q.push(mp(i, j)); //,cout<<i<<" "<<j<<endl;

    while (q.size()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();

        for (int t = 0; t < Q; t++) {
            int dx = vec[t].fi, dy = vec[t].se;

            if (has[x][y][t])
                continue;

            if (ok(x - dx, y - dy) && ans[x - dx][y - dy] == -1) {
                ans[x - dx][y - dy] = 1;
                q.push(mp(x - dx, y - dy));
            }
        }
    }

    while (q.size())
        q.pop();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (ans[i][j] == -1) {
                bool Flg = 0;

                for (int l = 0; l < vec.size(); l++)
                    if (!ok(i - vec[l].fi, j - vec[l].se))
                        Flg = 1;

                if (Flg)
                    ans[i][j] = 0;
            }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (ans[i][j] == 0)
                q.push(mp(i, j));

    while (q.size()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();

        for (int i = 0; i < vec.size(); i++) {
            int xx = x + vec[i].fi, yy = y + vec[i].se;

            if (ok(xx, yy) && ans[xx][yy] == -1)
                ans[xx][yy] = 0, q.push(mp(xx, yy));
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            putchar(ans[j][i] == 1 ? '#' : '.');

        putchar('\n');
    }

    putchar('\n');

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            putchar(ans[j][i] == 0 ? '.' : '#');

        putchar('\n');
    }
}
signed main() {
    int _ = 1;

    //  cin>>_;
    while (_--)
        solve();

    return 0;
}