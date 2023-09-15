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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<tuple<int, int, int, int>> edges;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edges.push_back({c, a, b, -1});
  }
  rep(i, q) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    edges.push_back({w, u, v, i});
  }
  sort(ALL(edges));
  vector<bool> ans(q);
  dsu uf(n);
  for (auto [w, u, v, idx] : edges) {
    if (idx != -1)
      ans.at(idx) = !uf.same(u, v);
    else
      uf.merge(u, v);
  }
  for (auto f : ans) cout << (f ? "Yes" : "No") << endl;
  return 0;
}