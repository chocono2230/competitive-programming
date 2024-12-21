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
  ll n, m;
  cin >> n >> m;
  ll x, y;
  cin >> x >> y;
  map<ll, set<ll>> xv, yv;
  rep(i, n) {
    ll xi, yi;
    cin >> xi >> yi;
    xv[xi].insert(yi);
    yv[yi].insert(xi);
  }
  ll ans = 0;
  rep(i, m) {
    char d;
    ll c;
    cin >> d >> c;
    auto fc = [&](bool flg, bool dd, ll ta) {
      if (flg) {
        swap(xv, yv);
        swap(x, y);
      }
      auto &pv = xv, &qv = yv;
      ll &p = x, &q = y;
      if (pv.find(p) == pv.end()) {
        q = ta;
        if (flg) {
          swap(xv, yv);
          swap(x, y);
        }
        return;
      }
      auto &se = pv[p];
      if (dd) {
        auto itr = se.upper_bound(q);
        if (itr != se.begin()) {
          itr--;
          while (1) {
            if (*itr < ta) break;
            ans++;
            qv[*itr].erase(p);
            if (itr == se.begin()) {
              se.erase(itr);
              break;
            }
            auto nxitr = prev(itr);
            se.erase(itr);
            itr = nxitr;
          }
        }
      } else {
        auto itr = se.lower_bound(q);
        while (itr != se.end()) {
          if (*itr > ta) break;
          ans++;
          qv[*itr].erase(p);
          itr = se.erase(itr);
        }
      }
      // cerr << flg << " " << dd << " " << q << " " << ta << endl;
      q = ta;
      if (flg) {
        swap(xv, yv);
        swap(x, y);
      }
    };
    if (d == 'D') fc(false, true, y - c);
    if (d == 'U') fc(false, false, y + c);
    if (d == 'L') fc(true, true, x - c);
    if (d == 'R') fc(true, false, x + c);
    // cerr << x << " " << y << endl;
  }
  cout << x << " " << y << " " << ans << endl;
  return 0;
}