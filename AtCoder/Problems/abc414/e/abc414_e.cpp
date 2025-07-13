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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  ll n;
  cin >> n;
  ll sz = 10000000;
  mint ans = 0;
  rep2(i, 2, sz) {
    if (i > n) break;
    ll p = n - i;
    ans += p - p / i;
  }
  if (sz > n) {
    cout << ans.val() << endl;
    return 0;
  }
  auto cc = [=](ll x) { return n / x; };
  ll now = sz;
  while (now < n) {
    ll nowc = cc(now);
    ll nxmn = now, nxmx = n + 1;
    while (nxmx - nxmn > 1) {
      ll mid = (nxmx + nxmn) / 2;
      if (cc(mid) == nowc)
        nxmn = mid;
      else
        nxmx = mid;
    }
    mint add = ((n - (nxmn - 1)) + (n - (now - 1)));
    add *= nxmx - now;
    add /= 2;
    add -= nowc * (nxmx - now);
    ans += add;
    now = nxmx;
  }
  cout << ans.val() << endl;
  return 0;
}