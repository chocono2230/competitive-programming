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
  ll a, m, l, r;
  cin >> a >> m >> l >> r;
  l -= a;
  r -= a;
  if (l <= 0) {
    ll c = (abs(l) + m - 1) / m * m + m;
    l += c;
    r += c;
  }
  ll rc = r / m;
  ll lc = (l - 1) / m;
  ll ans = rc - lc;
  cout << ans << endl;
  return 0;
}