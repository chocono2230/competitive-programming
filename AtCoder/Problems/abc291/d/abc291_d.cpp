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
  vector ab(n, vector<int>(2, 0));
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    ab.at(i) = {a, b};
  }
  vector<mint> base(2, 0);
  auto dp = base;
  dp.front() = 1;
  dp.back() = 1;
  rep2(i, 1, n) {
    auto nx = base;
    rep(p, 2) rep(q, 2) {
      if (ab.at(i - 1).at(p) == ab.at(i).at(q)) continue;
      nx.at(q) += dp.at(p);
    }
    swap(nx, dp);
  }
  mint ans = reduce(ALL(dp));
  cout << ans.val() << endl;
  return 0;
}