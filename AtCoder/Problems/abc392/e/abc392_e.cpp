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
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> gr(n, vector<pair<int, int>>());
  vector<pair<int, int>> edges(m);
  dsu uf(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back({b, i});
    gr.at(b).push_back({a, i});
    uf.merge(a, b);
    edges.at(i) = {a, b};
  }
  vector<bool> memo(n, false);
  vector<bool> use_edge(m, false);
  set<int> lds;
  rep(i, n) {
    if (memo.at(i)) continue;
    memo.at(i) = true;
    auto rc = [&](const auto &self, int now) -> void {
      memo.at(now) = true;
      for (auto [nx, nxei] : gr.at(now)) {
        if (memo.at(nx)) continue;
        use_edge.at(nxei) = true;
        self(self, nx);
      }
    };
    rc(rc, i);
    lds.insert(uf.leader(i));
  }
  vector<tuple<int, int, int>> ans;
  rep(i, m) {
    if (lds.size() == 1) break;
    if (use_edge.at(i)) continue;
    auto [a, b] = edges.at(i);
    auto itr = lds.begin();
    if (uf.same(*itr, a)) itr++;
    ans.push_back({i, b, *itr});
    uf.merge(a, *itr);
    lds.erase(*itr);
  }
  cout << ans.size() << endl;
  for (auto [i, j, k] : ans)
    cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
  return 0;
}