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
  vector<int> p(n);
  rep(i, n) {
    cin >> p.at(i);
    p.at(i)--;
  }
  vector<int> q(n);
  rep(i, n) {
    cin >> q.at(i);
    q.at(i)--;
  }
  vector<int> a(n);
  rep(i, n) { a.at(p.at(i)) = q.at(i); }
  vector base(k + 1, vector<mint>(n + 1, 0));
  auto dp = base;
  dp.front().back() = 1;
  rep(x, n) {
    auto nxdp = base;
    int now = a.at(x);
    rep(i, k + 1) rep(j, n + 1) {
      nxdp.at(i).at(min(j, now)) += dp.at(i).at(j);
      if (i != k && now < j) {
        nxdp.at(i + 1).at(j) += dp.at(i).at(j);
      }
    }
    swap(dp, nxdp);
  }
  mint ans = reduce(ALL(dp.back()));
  cout << ans.val() << endl;
  return 0;
}