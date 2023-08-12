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
  vector tree(n + n - 1, vector<int>());
  dsu uf(n + n - 1);
  vector<int> ld(n + n - 1);
  rep(i, ld.size()) ld.at(i) = i;
  vector<int> sz(n + n - 1, 0);
  rep(i, n) sz.at(i) = 1;
  rep(i, n - 1) {
    int p, q;
    cin >> p >> q;
    p--;
    q--;
    int pl = uf.leader(p);
    int ql = uf.leader(q);
    pl = ld.at(pl);
    ql = ld.at(ql);
    tree.at(i + n).push_back(pl);
    tree.at(i + n).push_back(ql);
    uf.merge(i + n, pl);
    uf.merge(i + n, ql);
    int l = uf.leader(i + n);
    ld.at(l) = i + n;
    sz.at(i + n) = sz.at(pl) + sz.at(ql);
  }

  vector<mint> ans(n, 0);
  auto dfs = [&](auto self, int now, mint p) {
    if (now < n) {
      ans.at(now) = p;
      return;
    }
    int x = 0, y = 0;
    int rx = 0, ry = 0;
    for (auto nx : tree.at(now)) {
      if (x == 0) {
        x = sz.at(nx);
        rx = nx;
      } else {
        y = sz.at(nx);
        ry = nx;
      }
    }
    mint xnx = p + mint(x) / mint(x + y);
    mint ynx = p + mint(y) / mint(x + y);
    self(self, rx, xnx);
    self(self, ry, ynx);
  };
  dfs(dfs, n + n - 2, 0);
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i).val();
  }
  cout << endl;

  return 0;
}