#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  rep(i, n) cin >> x.at(i);
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  vector<int> ans(q);
  vector qe(n, vector<pair<int, int>>());
  rep(i, q) {
    int v, k;
    cin >> v >> k;
    v--;
    k--;
    qe.at(v).push_back({k, i});
  }
  auto dfs = [&](const auto self, int now, int bf) -> vector<int> {
    vector<int> z;
    z.push_back(x.at(now));
    for (auto nx : tree.at(now)) {
      if (nx == bf) continue;
      auto r = self(self, nx, now);
      for (auto add : r) z.push_back(add);
    }
    sort(ALL(z), greater<int>());
    while (z.size() > 20) {
      z.pop_back();
    }
    for (auto [a, b] : qe.at(now)) {
      ans.at(b) = z.at(a);
    }
    return z;
  };
  dfs(dfs, 0, -1);
  for (auto p : ans) cout << p << endl;
  return 0;
}