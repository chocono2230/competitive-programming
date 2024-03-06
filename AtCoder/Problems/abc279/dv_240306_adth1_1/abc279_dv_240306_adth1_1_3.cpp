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
  const ll INF = 4e18;
  auto fc = [&](const ll co) -> pair<int, double> {
    if (co != 0 && b > LLONG_MAX / co) return {1, 0};
    return {0, b * co + a / sqrt(co + 1)};
  };

  ll l = 0, r = a + 1;
  while (r - l > 10) {
    ll ml = (r - l) / 3 + l;
    ll mr = (r - l) * 2 / 3 + l;
    if (fc(ml) <= fc(mr)) {
      r = mr;
    } else {
      l = ml;
    }
  }
  double ans = INF;
  ll ss = 100000;
  for (ll now = max(0LL, l - ss), co = 0; co < ss; now++, co++) {
    auto p = fc(now);
    if (p.first == 1) continue;
    ans = min(ans, p.second);
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}