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
  int n, k;
  cin >> n >> k;
  vector a(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> a.at(i).at(j);
  auto fc = [&]() {
    dsu uf(n);
    rep(l, n) rep2(r, l + 1, n) {
      bool f = false;
      rep(j, n) {
        if (a.at(l).at(j) + a.at(r).at(j) > k) f = true;
      }
      if (f) continue;
      uf.merge(l, r);
    }
    mint res = 1;
    auto grp = uf.groups();
    for (auto &v : grp) {
      mint r = 1;
      rep(i, v.size()) r *= (i + 1);
      res *= r;
    }
    return res;
  };
  mint ans = fc();
  rep(i, n) rep2(j, i + 1, n) swap(a.at(i).at(j), a.at(j).at(i));
  ans *= fc();
  cout << ans.val() << endl;
  return 0;
}