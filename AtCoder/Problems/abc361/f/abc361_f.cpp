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
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  ll ans = 1;
  ll rt = sqrt(n) - 1000;
  while (rt * rt <= n) {
    rt++;
  }
  rt--;
  int sz = 10000000;
  vector<bool> chk(sz);
  rep2(i, 2, sz) {
    if (chk.at(i)) continue;
    ll now = i;
    int co = 1;
    while (1) {
      if (LLONG_MAX / i < now) break;
      now *= i;
      co++;
      if (now < sz) {
        chk.at(now) = true;
      } else if (now <= n) {
        ans--;
      } else {
        break;
      }
    }
  }
  if (n < sz) {
    ans = 1;
    rep(i, n + 1) if (chk.at(i)) ans++;
  } else {
    rep(i, n + 1) if (chk.at(i)) ans++;
    ans += rt - sz;
  }
  cout << ans << endl;
  return 0;
}