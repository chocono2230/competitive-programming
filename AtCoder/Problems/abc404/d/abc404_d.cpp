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
  int n, m;
  cin >> n >> m;
  vector<ll> c(n);
  rep(i, n) cin >> c.at(i);
  vector a(n, vector<int>());
  rep(i, m) {
    int sz;
    cin >> sz;
    rep(j, sz) {
      int in;
      cin >> in;
      in--;
      a.at(in).push_back(i);
    }
  }

  ll ans = 1e18;
  int pw = 1;
  rep(i, n) pw *= 3;
  rep(bit, pw) {
    vector<int> vv(m, 0);
    ll add = 0;
    int nbit = bit;
    rep(i, n) {
      int co = nbit % 3;
      nbit /= 3;
      add += c.at(i) * co;
      for (auto now : a.at(i)) {
        vv.at(now) += co;
      }
    }
    bool f = false;
    rep(i, m) {
      if (vv.at(i) < 2) f = true;
    }
    if (!f) ans = min(ans, add);
  }
  cout << ans << endl;
  return 0;
}