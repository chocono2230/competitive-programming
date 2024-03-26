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
using mint = modint998244353;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  vector dp(n, vector(2, vector<mint>(0, 0)));
  auto dfs = [&](const auto &self, int now, int pr) -> void {
    vector res(2, vector<mint>(2, 0));
    res.at(1).at(1) = 1;
    res.at(0).at(0) = 1;
    for (auto nx : tree.at(now)) {
      if (nx == pr) continue;
      self(self, nx, now);
    }
    for (auto nx : tree.at(now)) {
      if (nx == pr) continue;
      auto &nxdp = dp.at(nx);
      vector nxres(2,
                   vector<mint>(nxdp.at(0).size() + res.at(0).size() - 1, 0));
      rep(i, res.at(0).size()) rep(j, nxdp.at(0).size()) {
        nxres.at(0).at(i + j) +=
            res.at(0).at(i) * (nxdp.at(0).at(j) + nxdp.at(1).at(j));
        nxres.at(1).at(i + j) += res.at(1).at(i) * nxdp.at(0).at(j);
        if (i + j > 0)
          nxres.at(1).at(i + j - 1) += res.at(1).at(i) * nxdp.at(1).at(j);
      }
      swap(res, nxres);
    }
    dp.at(now) = res;
  };
  dfs(dfs, 0, -1);
  rep2(i, 1, n + 1) cout << (dp.at(0).at(0).at(i) + dp.at(0).at(1).at(i)).val()
                         << endl;
  return 0;
}