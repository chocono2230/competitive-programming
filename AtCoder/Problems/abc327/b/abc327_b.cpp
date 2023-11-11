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
  ll b;
  cin >> b;
  ll ans = 1;
  auto fc = [](const ll p) -> ll {
    ll res = 1;
    for (ll i = 0; i < p; i++) {
      res *= p;
    }
    return res;
  };
  while (1) {
    ll r = fc(ans);
    if (r == b) break;
    if (r > b) {
      cout << -1 << endl;
      return 0;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}