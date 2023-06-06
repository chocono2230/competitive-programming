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
  ll a, b;
  cin >> a >> b;
  ll l = 0, r = (a + b - 1) / b;
  auto fc = [&](ll c) -> double {
    ll g = c + 1;
    return a / sqrt(g) + b * c;
  };
  while (r - l > 10) {
    // cerr << l << " " << r << endl;
    ll ml = l + (r - l) / 3, mr = l + (r - l) * 2 / 3;
    if ((r - l) % 3 != 0) mr += 2;
    if (fc(ml) < fc(mr)) {
      r = mr;
    } else {
      l = ml;
    }
  }
  double ans = 8e18;
  for (ll i = l; i <= r; i++) {
    // cerr << i << " " << fc(i) << endl;
    ans = min(ans, fc(i));
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}