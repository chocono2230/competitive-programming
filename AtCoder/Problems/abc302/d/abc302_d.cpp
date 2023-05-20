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
  int n, m;
  ll d;
  cin >> n >> m >> d;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> b(m);
  rep(i, m) cin >> b.at(i);
  sort(ALL(b));
  ll ans = -1;
  for (auto now : a) {
    ll ta = now + d;
    auto itr = upper_bound(ALL(b), ta);
    if (itr == b.begin()) continue;
    itr--;
    if (abs(*itr - now) <= d) {
      ans = max(ans, *itr + now);
    }
  }
  cout << ans << endl;
  return 0;
}