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
  ll n;
  cin >> n;
  ll ans = 0;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i != 0) continue;
    ll j = n / i;
    auto fc = [&](ll now) -> ll {
      ll m = now - 1;
      if (m == 0) return 0;
      if (n / m == n % m) return m;
      return 0;
    };
    ans += fc(i);
    ans += fc(j);
  }
  cout << ans << endl;
  return 0;
}