/**
 * author: LightSky
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
typedef long long  ll;

#define int ll

const int LL_INF = int(1e17);
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void ask(int i) {
    cout << "? " << i << endl;
}

void solve(vector<int> &ans, vector<int> &pos, int lb, int ub) {
    int sz = int(pos.size());
    if (!sz) return;

    int idx = RNG() % sz, piv = pos[idx];

    vector<int> l, g;

    // make x = piv
    while (true) {
        ask(piv);
        char c;
        cin >> c;
        if (c == '=') break;
    }

    for (auto &y: pos) {
        if (y == piv) continue;
        ask(y);
        char c;
        cin >> c;

        assert(c != '=');

        if (c == '>') g.push_back(y);
        else l.push_back(y);
        // then make x = piv again
        ask(piv);
        cin >> c;
    }

    ans[piv] = lb + int(l.size()) + 1;

    solve(ans, g, ans[piv], ub);
    solve(ans, l, lb, ans[piv]);
}

int32_t main()
{
    #if defined(_DEBUG)
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tests = 1;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;

        vector<int> ans(n + 1), pos;
        for (int i = 1; i <= n; i++) pos.push_back(i);

        solve(ans, pos, 0, n + 1);

        cout << "! ";
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
