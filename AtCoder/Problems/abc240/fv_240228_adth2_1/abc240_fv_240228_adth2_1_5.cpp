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

void fc() {
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> xy(n);
  ll ans = 0, now = 0, sp = 0;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    ll ds = x * y;
    ll nxsp = sp + ds;
    if (i == 0) {
      ans = x;
    }
    if (sp > 0 && nxsp < 0) {
      ll co = sp / abs(x);
      ll t = now;
      t += sp * co;
      t += co * (co + 1) / 2 * x;
      ans = max(ans, t);
    }
    now += sp * y;
    now += y * (y + 1) / 2 * x;
    ans = max(ans, now);
    sp = nxsp;
  }
  cout << ans << endl;
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    fc();
  }
  return 0;
}