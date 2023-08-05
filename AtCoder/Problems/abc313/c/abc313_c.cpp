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
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  ll sum = reduce(ALL(a));
  ll t = sum / n;
  ll x = n * t + n - sum;
  sort(ALL(a));
  // cerr << t << " " << x << endl;
  ll ans = 0;
  rep(i, x) {
    if (a.at(i) >= t) break;
    ans += t - a.at(i);
  }
  ll p = 0;
  rrep2(i, x, n) {
    if (a.at(i) <= t + 1) break;
    p += a.at(i) - (t + 1);
  }
  ans = max(ans, p);
  cout << ans << endl;
  return 0;
}