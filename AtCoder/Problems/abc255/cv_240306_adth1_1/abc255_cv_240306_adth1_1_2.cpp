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
  ll x, a, d, n;
  cin >> x >> a >> d >> n;
  ll p = a, q = a + d * (n - 1);
  if (p > q) swap(p, q);
  ll ans = min(abs(x - p), abs(x - q));
  if (p < x && x < q) {
    ll z = x - a;
    ll co = z / d;
    assert(co >= 0);
    ans = min({ans, abs(x - (a + co * d)), abs(x - (a + (co + 1) * d))});
  }
  cout << ans << endl;
  return 0;
}