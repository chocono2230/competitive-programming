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
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  sort(ALL(a));
  ll sum = reduce(ALL(a));
  ll p = sum / n;
  ll ans = 0;
  rep(i, n) {
    if (a.at(i) >= p) break;
    ans += p - a.at(i);
  }
  ll add = 0;
  ll q = p;
  if (sum % n != 0) q++;
  rrep(i, n) {
    if (a.at(i) <= q) break;
    add += a.at(i) - q;
  }
  ans = max(ans, add);
  cout << ans << endl;
  return 0;
}