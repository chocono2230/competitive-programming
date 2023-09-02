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
  rep(i, n) rep(j, n) {
    ev.push_back(x.at(i) + y.at(j));
    ev.push_back(x.at(i) - y.at(j) - 1);
  }
  sort(ALL(ev));
  ll ans = 0;
  rep(i, ev.size() - 1) {
    ll now = ev.at(i + 1);
    auto chk = [&]() {
      vector<ll> v;
      rep(i, n) v.push_back(abs(now - x.at(i)));
      sort(ALL(v));
      rep(i, n) {
        if (v.at(i) > y.at(i)) return false;
      }
      return true;
    };
    if (chk()) ans += now - ev.at(i);
  }
  cout << ans << endl;
  return 0;
}