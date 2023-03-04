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
  long double h, w;
  cin >> h >> w;
  if (h > w) swap(h, w);
  long double pi = acos(-1);
  long double ok = 15.0 * pi / 180.0, ng = 30.0 * pi / 180.0;
  rep(_i, 300) {
    long double mid = (ok + ng) / 2;
    auto fc = [&]() -> bool {
      double x = h / cos(mid);
      double t = 30.0 * pi / 180.0 - mid;
      return w > x * cos(t);
    };
    if (fc())
      ok = mid;
    else
      ng = mid;
  }
  long double m = (ok + ng) / 2;
  cerr << m / pi * 180 << endl;
  long double ans = h / cos(m);
  cout << fixed << setprecision(11) << ans << endl;
  return 0;
}