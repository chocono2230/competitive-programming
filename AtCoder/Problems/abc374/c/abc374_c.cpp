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
  vector<int> v(n);
  rep(i, n) cin >> v.at(i);
  const ll INF = 1e18;
  ll ans = INF;
  rep(bit, 1 << n) {
    ll x = 0, y = 0;
    rep(i, n) {
      if ((bit & (1 << i)) == 0)
        x += v.at(i);
      else
        y += v.at(i);
    }
    ans = min(ans, max(x, y));
  }
  cout << ans << endl;
  return 0;
}