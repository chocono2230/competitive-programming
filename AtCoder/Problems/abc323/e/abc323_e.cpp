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
  int n, x;
  cin >> n >> x;
  vector<int> t(n);
  rep(i, n) cin >> t.at(i);
  vector<mint> dp(x + 1, 0);
  dp.front() = 1;
  mint all = 0, ta = 0;
  mint md = mint(1) / n;
  rep(i, x + 1) {
    mint now = dp.at(i) * md;
    rep(j, n) {
      int ni = i + t.at(j);
      if (ni >= x + 1) {
        if (j == 0) ta += now;
        all += now;
      } else {
        dp.at(ni) += now;
      }
    }
  }
  mint ans = ta / all;
  cout << ans.val() << endl;
  return 0;
}