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

ll msq(ll p) {
  ll r = sqrt(p);
  if (r > 12)
    r -= 10;
  else
    r -= 1;
  while (1) {
    ll nxr = r + 1;
    if (nxr * nxr > p) return r;
    r = nxr;
  }
};

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  set<ll> se;
  rep2(i, 2, 1000005) {
    ll now = (ll)i * i * i;
    while (now <= n) {
      ll sr = msq(now);
      if (sr * sr != now) se.insert(now);
      if (LLONG_MAX / i < now) break;
      now *= i;
    }
  }
  // for (auto now : se) cerr << now << " ";
  // cerr << endl;
  ans += se.size();
  ans += msq(n);
  cout << ans << endl;
  return 0;
}