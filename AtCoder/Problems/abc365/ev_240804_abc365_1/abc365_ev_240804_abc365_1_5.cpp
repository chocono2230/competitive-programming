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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  ll ans = 0;
  vector base(2, vector<int>(30, 0));
  auto dp = base;
  rep(p, n) {
    int now = a.at(p);
    auto nxdp = base;
    rep(i, 30) {
      int idx = (((now & (1 << i)) != 0) ? 0 : 1);
      ll co = dp.at(idx).at(i);
      ans += (1LL << i) * co;
      if (idx == 0) {
        nxdp.at(1).at(i) = dp.at(0).at(i) + 1;
        nxdp.at(0).at(i) = dp.at(1).at(i);
      } else {
        nxdp.at(0).at(i) = dp.at(0).at(i) + 1;
        nxdp.at(1).at(i) = dp.at(1).at(i);
      }
    }
    swap(dp, nxdp);
    // rep(i, 5) cerr << dp.at(0).at(i) << " ";
    // cerr << endl;
    // rep(i, 5) cerr << dp.at(1).at(i) << " ";
    // cerr << endl;
    // cerr << "-------------" << endl;
  }
  cout << ans << endl;
  return 0;
}