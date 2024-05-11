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
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  sort(ALL(a));
  ll mx = 100'000'000;
  ll ans = 0;
  ll sum = reduce(ALL(a));
  while (a.size() != 1) {
    ll now = a.back();
    sum -= now;
    a.pop_back();
    ans += sum + now * a.size();
    ll lm = mx - now;
    ll co = lower_bound(ALL(a), lm) - a.begin();
    ans -= mx * (a.size() - co);
  }
  cout << ans << endl;
  return 0;
}