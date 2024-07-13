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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector dp(n, vector(n, vector<mint>(n + 1, 0)));
  vector<mint> ans(n + 1, 0);
  rrep(i, n) {
    rep2(j, i + 1, n) {
      dp.at(i).at(j).at(2) = 1;
      int d = a.at(j) - a.at(i);
      rep2(k, j + 1, n) {
        if (a.at(k) - a.at(j) != d) continue;
        rep(l, n) { dp.at(i).at(j).at(l + 1) += dp.at(j).at(k).at(l); }
      }
    }
  }
  rep(i, n) rep(j, n) rep(k, n + 1) ans.at(k) += dp.at(i).at(j).at(k);
  ans.at(1) = n;
  rep2(i, 1, n + 1) {
    if (i != 1) cout << " ";
    cout << ans.at(i).val();
  }
  cout << endl;
  return 0;
}