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
  vector<ll> x(n);
  rep(i, n) cin >> x.at(i);
  vector<ll> y(n);
  rep(i, n) cin >> y.at(i);
  vector<ll> ev;
  for (auto xx : x) {
    for (auto yy : y) {
      ev.push_back(xx + yy);
      ev.push_back(xx - yy - 1);
    }
  }
  sort(ALL(ev));
  ll ans = 0;
  rep(i, ev.size() - 1) {
    ll prev = ev.at(i), now = ev.at(i + 1);
    bool f = false;
    vector<ll> d(n);
    rep(i, n) d.at(i) = abs(now - x.at(i));
    sort(ALL(d));
    rep(i, n) {
      if (d.at(i) > y.at(i)) f = true;
    }
    if (!f) ans += now - prev;
  }
  cout << ans << endl;
  return 0;
}