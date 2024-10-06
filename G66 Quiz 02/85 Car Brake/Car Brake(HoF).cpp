#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, K;
    cin >> n >> m >> K;
    vector<tuple<int, int, int>> operations;
    vector<pair<int, int>> q2;
    for (int i = 1; i <= n; i++) {
        int t, d; cin >> t >> d;
        operations.push_back({t, 0, d});
    }
    operations.push_back({0, 0, 0});
    for (int i = 0; i < m; i++) {
        int a, q; cin >> a >> q;
        if (a == 1) operations.push_back({q, 1, i});
        else q2.push_back({q, i});
    }
    sort(q2.begin(), q2.end());
    sort(operations.begin(), operations.end());
    vector<int> ans(m);
    for (auto &[ti, op, sp] : operations) {
        if (op == 0) K = max(K-sp, 0);
        else if (op == 1) ans[sp] = K;
        while (!q2.empty() and K < q2.back().first) {
            ans[q2.back().second] = ti;
            q2.pop_back();
        }
    }
    for (int x : ans) cout << x << "\n";
}
